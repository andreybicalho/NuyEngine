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
	    3.0f,  3.0f, 0.0f,
	   10.0f,  3.0f, 0.0f,
	   10.0f,  5.0f, 0.0f,
	    3.0f,  5.0f, 0.0f
	};

	GLushort indices[] = 
	{
		0, 1, 2,
		0, 2, 3
	};

	GLfloat colorsA[] = /* colors must be per vertex, one color for each vertex, since we have 4 vertices there must be 4 colors*/
	{
	 /* R  G  B  A */
		1, 0, 1, 1,
		1, 0, 1, 1,
		1, 0, 1, 1,
		1, 0, 1, 1
	};

	GLfloat colorsB[] =
	{
	 /*  R     G     B     A */
		0.2f, 0.3f, 0.8f, 1.0f,
		0.2f, 0.3f, 0.8f, 1.0f,
		0.2f, 0.3f, 0.8f, 1.0f,
		0.2f, 0.3f, 0.8f, 1.0f
	};


	nuy::graphics::VertexArray sprint1, sprint2;
	nuy::graphics::IndexBuffer ibo(indices, 6);

	sprint1.AddBuffer(new nuy::graphics::Buffer(vertices, 4 * 3, 3), 0);
	sprint1.AddBuffer(new nuy::graphics::Buffer(colorsA, 4 * 4, 4), 1);

	sprint2.AddBuffer(new nuy::graphics::Buffer(vertices, 4 * 3, 3), 0);
	sprint2.AddBuffer(new nuy::graphics::Buffer(colorsB, 4 * 4, 4), 1);
#endif
	nuy::maths::Matrix4 ortho = nuy::maths::Matrix4::Orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f); // 16x9 space hence 16:9 aspect ratio

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
		shader.SetUniform2f("in_light_pos", nuy::maths::Vector2((float)(x * 16.0f / 960.0f), (float)(9.0f - y * 9.0f / 540.0f)));
		//std::cout << x << ", " << y << std::endl;
#if 0
		glDrawArrays(GL_TRIANGLES, 0, 3);
#else
		sprint1.Bind();
		ibo.Bind();
		shader.SetUniformMat4("ml_matrix", nuy::maths::Matrix4::Translate(nuy::maths::Vector3(0, 0, 0)));
		glDrawElements(GL_TRIANGLES, ibo.GetCount(), GL_SHORT, 0/*0 because we have already bind our indices*/);
		ibo.Unbind();
		sprint1.Unbind();


		sprint2.Bind();
		ibo.Bind();
		shader.SetUniformMat4("ml_matrix", nuy::maths::Matrix4::Translate(nuy::maths::Vector3(-2, 2, 0)));
		glDrawElements(GL_TRIANGLES, ibo.GetCount(), GL_UNSIGNED_SHORT, 0/*0 because we have already bind our indices*/);
		ibo.Unbind();
		sprint2.Unbind();
#endif
		window.Update();
	}



	return 0;
}