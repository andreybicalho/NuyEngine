#pragma once

#include <iostream>

#include <GLFW/glfw3.h>

namespace nuy { namespace graphics {

	class Window
	{
	private:
		int Width, Height;
		const char* Title;
		GLFWwindow* MainWindow;
	public:
		Window(const char* title, int width, int height);
		~Window();

		void Update();
		bool IsClosed() const;
		void Clear() const;

		inline int GetWidth() const { return Width; }
		inline int GetHeight() const { return Height; }
	private:
		bool Init();
	};
} }