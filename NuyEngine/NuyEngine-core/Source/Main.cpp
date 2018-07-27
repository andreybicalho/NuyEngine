#include <iostream>

#include "Maths/Maths.h"
#include "Graphics/Window.h"
#include "Graphics/Shader.h"
#include "Graphics/Buffers/Buffer.h"
#include "Graphics/Buffers/IndexBuffer.h"
#include "Graphics/Buffers/VertexArray.h"


int main()
{
	nuy::graphics::Window window("Nuy Engine", 960, 540);
	//glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

#if 0
	GLfloat vertices[] =
	{
	   /* X      Y     Z */
		 0.0f,  0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f
	};

	GLuint vbo; 
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3 /* 3 components per vertex (X, Y, Z)*/, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
#else
	GLfloat vertices[] =
	{
	   /* X      Y     Z */
	   -0.5f, -0.5f, 0.0f,
	    0.5f, -0.5f, 0.0f,
		0.5f,  0.5f, 0.0f,
	   -0.5f,  0.5f, 0.0f
	};

	GLushort indices[] = 
	{
		0, 1, 2,
		0, 2, 3
	};

	nuy::graphics::VertexArray vao;
	nuy::graphics::Buffer* vbo = new nuy::graphics::Buffer(vertices, 4 * 3 /* 4 vertices with 3 components (x,y,z) */, 3 /* 3 components x,y,z*/);
	nuy::graphics::IndexBuffer ibo(indices, 6 /* our square is made with two triangles, each triangle has 3 vertices, total of 6 vertices*/);
	vao.AddBuffer(vbo, 0 /*location = 0 in our shader*/);
#endif
	nuy::maths::Matrix4 ortho = nuy::maths::Matrix4::Orthographic(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);

	nuy::graphics::Shader shader("Source/Resources/vertexShader.shader", "Source/Resources/fragmentShader.shader");
	shader.Enable();
	shader.SetUniformMat4("pr_matrix", ortho);
	//shader.SetUniformMat4("ml_matrix", nuy::maths::Matrix4::Translate(nuy::maths::Vector3(0.6, 0, 0)));
	//shader.SetUniformMat4("ml_matrix", nuy::maths::Matrix4::Rotate(45.0f, nuy::maths::Vector3(0, 0, 1)));

	shader.SetUniform2f("in_light_pos", nuy::maths::Vector2(0.0f, 0.0f));
	shader.SetUniform4f("in_color", nuy::maths::Vector4(0.2f, 0.1f, 0.0f, 1.0f));

	while (!window.IsClosed())
	{
		window.Clear();
		double x, y;
		window.GetMousePosition(x, y);
		x = (x / 960.0f - 0.5f);
		y = (0.5f - y / 540.0f);
		//std::cout << x << ", " << y << std::endl;
		shader.SetUniform2f("in_light_pos", nuy::maths::Vector2((float)x, (float)y));
#if 0
		glDrawArrays(GL_TRIANGLES, 0, 3);
#else
		vao.Bind();
		ibo.Bind();
		glDrawElements(GL_TRIANGLES, ibo.GetCount(), GL_UNSIGNED_SHORT, 0/*0 because we have already bind our indices*/);
		ibo.Unbind();
		vao.Unbind();
#endif
		window.Update();
	}



	return 0;
}