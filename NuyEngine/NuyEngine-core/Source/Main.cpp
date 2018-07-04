#include <iostream>

#include "Graphics/Window.h"

int main()
{
	nuy::graphics::Window window("Nuy Engine", 960, 540);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	GLuint vao; 
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	while (!window.IsClosed())
	{
		window.Clear();
#if 1
		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f,  0.5f);
		glVertex2f( 0.5f,  0.5f);
		glVertex2f( 0.5f, -0.5f);
		glEnd();
#else
		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
#endif

		window.Update();
	}



	return 0;
}