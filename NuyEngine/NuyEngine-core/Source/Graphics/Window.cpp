#include "Window.h"

namespace nuy { namespace graphics {	
	
	Window::Window(const char* title, int width, int height)
		: Title(title), Width(width), Height(height)
	{
		if (!Init())
		{
			glfwTerminate();
		}

		for (int i = 0; i < MAX_KEYS; i++)
		{
			Keys[i] = false;
		}

		for (int i = 0; i < MAX_MOUSE_BUTTONS; i++)
		{
			MouseButtons[i] = false;
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
		glfwSetWindowSizeCallback(MainWindow, window_resize);
		glfwSetWindowUserPointer(MainWindow, this);
		glfwSetKeyCallback(MainWindow, key_callback);
		glfwSetMouseButtonCallback(MainWindow, mouse_button_callback);
		glfwSetCursorPosCallback(MainWindow, cursor_position_callback);

		if (glewInit() != GLEW_OK)
		{
			std::cout << "Could not initialize GLEW!" << std::endl;
			return false;
		}

		std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;
		return true;
	}

	void Window::Update()
	{
		GLenum error = glGetError();
		if (error != GL_NO_ERROR)
		{
			std::cout << "OpenGL Error: " << error << std::endl;
		}
				
		glfwPollEvents();
		glfwSwapBuffers(MainWindow);
	}

	bool Window::IsClosed() const
	{
		return glfwWindowShouldClose(MainWindow) == 1;
	}

	void Window::Clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	bool Window::IsKeyPressed(unsigned int keyCode) const
	{
		// TODO(andrey): log this
		if(keyCode >= MAX_KEYS)
		{ 
			return false;
		}

		return Keys[keyCode];
	}

	bool Window::IsMouseButtonPressed(unsigned int buttonCode) const
	{
		// TODO(andrey): log this
		if (buttonCode >= MAX_MOUSE_BUTTONS)
		{
			return false;
		}

		return MouseButtons[buttonCode];
	}

	void Window::GetMousePosition(double& xpos, double& ypos) const
	{
		xpos = MouseX;
		ypos = MouseY;
	}

	/*
	*	Window Resize Callback. Resizes window viewport.
	*
	*	@param GLFWwindow *window			window to set
	*	@param int width					new window width in pixels
	*	@param int height					new window height in pixels
	*/
	void window_resize(GLFWwindow *window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	/*
	*	The callback to be notified when a physical key, usually the keyboard, is pressed or released or when it repeats.
	*
	*	@param GLFWwindow* window			Window where the key was pressed.
	*	@param int key						The key code.
	*	@param int scancode					The scancode is unique for every key, regardless of whether it has a key token. Scancodes are platform-specific but consistent over time, so key
    *										will have different scancodes depending on the platform.
	*	@param int action					The action is one of GLFW_PRESS, GLFW_REPEAT or GLFW_RELEASE. The key will be GLFW_KEY_UNKNOWN if GLFW lacks a key token for it
	*	@param int mods						
	*/
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		Window* win = (Window*) glfwGetWindowUserPointer(window);
		
		win->Keys[key] = action != GLFW_RELEASE;
	}

	/*
	*	The callback to be notified when mouse button is pressed or released or when it repeats.
	*
	*	@param GLFWwindow* window			Window where the button was pressed.
	*	@param int key						The mouse key code.
	*	@param int action					The action is one of GLFW_PRESS or GLFW_RELEASE.
	*	@param int mods
	*/
	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
	{
		Window* win = (Window*) glfwGetWindowUserPointer(window);

		win->MouseButtons[button] = action != GLFW_RELEASE;
	}

	/*
	*	The callback to be notified when mouse x and y coordinates are changing in position.
	*
	*	@param GLFWwindow* window			Window where the cursor position is over.
	*	@param double xpos					The mouse X coordinate.
	*	@param double ypos					The mouse Y coordinate.
	*/
	void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
	{
		Window* win = (Window*) glfwGetWindowUserPointer(window);

		win->MouseX = xpos;
		win->MouseY = ypos;
	}

} }