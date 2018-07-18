#include <iostream>

#include "Graphics/Window.h"
#include "Maths/Maths.h"

int main()
{
	nuy::graphics::Window window("Nuy Engine", 960, 540);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	GLuint vao; 
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	{
		nuy::maths::Matrix4 position(1.f);
			
		position.elements[1 + 2 * 4] = 9999;

		std::cout << position << std::endl;

		position = nuy::maths::Matrix4::Translate(nuy::maths::Vector3(20, 300, 4));

		std::cout << position << std::endl;

		position *= nuy::maths::Matrix4::Identity();

		std::cout << position << std::endl;

		nuy::maths::Vector4& vec = position.columns[3];

		std::cout << &position.elements[12] << " = " << position.elements[12] << std::endl;
		std::cout << &position.columns[3].X << " = " << position.columns[3].X << std::endl;
		std::cout << &vec.X << " = " << vec.X << std::endl;
	}




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
		if(window.IsKeyPressed(GLFW_KEY_A) || window.IsMouseButtonPressed(GLFW_MOUSE_BUTTON_1))
		{ 
			std::cout << "PRESSED!" << std::endl;
		}

		double x, y;
		window.GetMousePosition(x, y);
		std::cout << x << ", " << y << std::endl;
		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
#endif

		window.Update();
	}



	return 0;
}