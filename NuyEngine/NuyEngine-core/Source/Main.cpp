#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

int main()
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(960, 540, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)
		std::cout << "Error!" << std::endl;

	// opengl version
	std::cout << glGetString(GL_VERSION) << std::endl;

	while (!glfwWindowShouldClose(window))
	{
		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();


	std::cout << std::endl << "Press any key to finish..." << std::endl;
	std::cin.get();
	return 0;
}