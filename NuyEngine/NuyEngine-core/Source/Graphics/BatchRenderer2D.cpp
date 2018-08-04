#include "BatchRenderer2D.h"


namespace nuy { namespace graphics {

	BatchRenderer2D::BatchRenderer2D()
	{
		Init();
	}

	BatchRenderer2D::~BatchRenderer2D()
	{
		delete IBO;
		glDeleteBuffers(1, &VBO_ID);
	}	

	void BatchRenderer2D::Init()
	{
		glGenBuffers(1, &VAO_ID);
		glGenBuffers(1, &VBO_ID);

		/* NOTE(andrey): Teaching OpenGL how to interpret memory according to our VertexData. */
		glBindVertexArray(VAO_ID);
		glBindBuffer(GL_ARRAY_BUFFER, VBO_ID);
		glBufferData(GL_ARRAY_BUFFER, RENDERER_BUFFER_SIZE, NULL, GL_DYNAMIC_DRAW);
		glEnableVertexAttribArray(SHADER_VERTEX_INDEX);
		glEnableVertexAttribArray(SHADER_COLOR_INDEX);
		glVertexAttribPointer(SHADER_VERTEX_INDEX, 3, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (const GLvoid*) 0);
		glVertexAttribPointer(SHADER_COLOR_INDEX, 4, GL_FLOAT, GL_FALSE, RENDERER_VERTEX_SIZE, (const GLvoid*)(3 * sizeof(GLfloat)));
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		GLushort indices[RENDERER_INDICES_SIZE];

		/* 
		 * NOTE(andrey): building indices for ours rectangles.
		 * Sprite is inside a rectangle which is made by two triangles.
		 * Triangles have 3 vertices.
		 */

		int offset = 0;
		for(int i=0; i < RENDERER_INDICES_SIZE; i += 6)
		{
			// first triangle
			indices[  i  ] = offset + 0;
			indices[i + 1] = offset + 1;
			indices[i + 2] = offset + 2;

			// second triangle
			indices[i + 3] = offset + 2;
			indices[i + 4] = offset + 3;
			indices[i + 5] = offset + 0;
			
			// NOTE(andrey):
			// vertices    0, 1, 2
			//             2, 3, 0
			// if I would have another rectangle made by two triangles like this, it would be
			// 4, 5, 6
			// 6, 7, 4
			// can you see that pattern? they are added up by +4, hence, our offset is 4.
			offset += 4;
		}

		IBO = new IndexBuffer(indices, RENDERER_INDICES_SIZE);

		glBindVertexArray(0);
	}

	void BatchRenderer2D::Begin()
	{
		glBindBuffer(GL_ARRAY_BUFFER, VBO_ID);
		_Buffer = (VertexData*) glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
	}

	void BatchRenderer2D::Submit(const Renderable2D* renderable)
	{
		/*
		* NOTE(andrey): Our sprite is made up of 4 vertices, right?
		* Lets Access all 4 vertices from memory interpreted as our VertexData array and put it our buffer for drawing it latter.
		*/

		// first vertex
		const maths::Vector3& position = renderable->GetPosition();
		const maths::Vector4& color = renderable->GetColor();
		const maths::Vector2& size = renderable->GetSize();

		_Buffer->vertex = position;
		_Buffer->color = color;
		_Buffer++; // advancing in memory

		// second vertex
		_Buffer->vertex = maths::Vector3(position.X, position.Y + size.Y, position.Z);
		_Buffer->color = color;
		_Buffer++;

		// third vertex
		_Buffer->vertex = maths::Vector3(position.X + size.X, position.Y + size.Y, position.Z);
		_Buffer->color = color;
		_Buffer++;

		// fourth vertex
		_Buffer->vertex = maths::Vector3(position.X + size.X, position.Y, position.Z);
		_Buffer->color = color;
		_Buffer++; // FIX(andrey): should we advance it once more since we have only 4 vertices?

		// NOTE(andrey): again, a rectangle is made up of 4 vertices, which have two triangles, and a triangle is made up of 3 vertices (elements), 
		// and thus we end up with 6 indices (6 elements)
		IndexCount += 6;
	}

	void BatchRenderer2D::End()
	{
		glUnmapBuffer(GL_ARRAY_BUFFER);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void BatchRenderer2D::Draw()
	{
		glBindVertexArray(VAO_ID);
		IBO->Bind();

		glDrawElements(GL_TRIANGLES, IndexCount, GL_UNSIGNED_SHORT, NULL);

		IBO->Unbind();
		glBindVertexArray(0);

		IndexCount = 0; // NOTE(andrey): after we draw everything, we need to reset IndexCount (which is the number of elements we are going to draw)
	}
} }