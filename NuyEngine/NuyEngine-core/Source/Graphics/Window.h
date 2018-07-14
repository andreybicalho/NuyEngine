#pragma once

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace nuy { namespace graphics {


#define MAX_KEYS			1024
#define MAX_MOUSE_BUTTONS	32

	class Window
	{	
	private:
		int Width, Height;
		const char* Title;
		GLFWwindow* MainWindow;

		static bool Keys[MAX_KEYS]; // indexes are key codes
		static bool MouseButtons[MAX_MOUSE_BUTTONS];
		static double MouseX, MouseY;
	public:
		Window(const char* title, int width, int height);
		~Window();

		void Update();
		bool IsClosed() const;
		void Clear() const;

		inline int GetWidth() const { return Width; }
		inline int GetHeight() const { return Height; }

		static bool IsKeyPressed(unsigned int keyCode);
		static bool IsMouseButtonPressed(unsigned int buttonCode);
		static void GetMousePosition(double& xpos, double& ypos);
	private:
		bool Init();
		
		// Inputs callbacks
		friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		friend static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		friend static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
	};
} }