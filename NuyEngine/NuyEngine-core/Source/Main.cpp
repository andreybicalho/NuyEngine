#include <GLFW/glfw3.h>

#include <iostream>

#include "Graphics/Window.h"

int main()
{
	nuy::graphics::Window window("Nuy Engine", 960, 540);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	std::cout << glGetString(GL_VERSION) << std::endl;

	while (!window.IsClosed())
	{
		window.Clear();

		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f,  0.5f);
		glVertex2f( 0.5f,  0.5f);
		glVertex2f( 0.5f, -0.5f);
		glEnd();

		window.Update();
	}



	return 0;
}