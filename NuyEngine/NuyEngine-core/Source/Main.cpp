#include <iostream>

#include "Graphics/Window.h"
#include "Maths/Maths.h"
#include "Graphics/Shader.h"

int main()
{
	nuy::graphics::Window window("Nuy Engine", 960, 540);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);


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

	nuy::maths::Matrix4 ortho = nuy::maths::Matrix4::Orthographic(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);

	nuy::graphics::Shader shader("Source/Resources/vertexShader.shader", "Source/Resources/fragmentShader.shader");
	shader.Enable();
	shader.SetUniformMat4("pr_matrix", ortho);
	shader.SetUniformMat4("ml_matrix", nuy::maths::Matrix4::Translate(nuy::maths::Vector3(0.6, 0, 0)));
	shader.SetUniformMat4("ml_matrix", nuy::maths::Matrix4::Rotate(45.0f, nuy::maths::Vector3(0, 0, 1)));


	while (!window.IsClosed())
	{
		window.Clear();
		glDrawArrays(GL_TRIANGLES, 0, 6);
		window.Update();
	}



	return 0;
}