#include "Window.h"

namespace nuy { namespace graphics {	

	/*
		Window Resize Callback. Resizes window viewport.
	*/
	void windowResize(GLFWwindow *window, int width, int height);

	Window::Window(const char* title, int width, int height)
		: Title(title), Width(width), Height(height)
	{
		if (!Init())
		{
			glfwTerminate();
		}
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	bool Window::Init()
	{
		if (!glfwInit())
		{
			std::cout << "Failed to initialize GLFW!" << std::endl;
			return false;
		}

		MainWindow = glfwCreateWindow(Width, Height, Title, nullptr, nullptr);
		if(!MainWindow)
		{ 
			std::cout << "Failed to create GLFW window!" << std::endl;
			return false;
		}

		glfwMakeContextCurrent(MainWindow);

		glfwSetWindowSizeCallback(MainWindow, windowResize);

		return true;
	}

	void Window::Update()
	{
		glfwSwapBuffers(MainWindow);
				
		glfwPollEvents();
	}

	bool Window::IsClosed() const
	{
		return glfwWindowShouldClose(MainWindow) == 1;
	}

	void Window::Clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	/*
	*	Window Resize Callback. Resizes window viewport.
	*
	*	@param GLFWwindow *window			window to set
	*	@param int width					new window width in pixels
	*	@param int height					new window height in pixels
	*/
	void windowResize(GLFWwindow *window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

} }