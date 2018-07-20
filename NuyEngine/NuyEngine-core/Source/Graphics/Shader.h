#pragma once

#include <GL/glew.h>

namespace nuy { namespace graphics {
	
	class Shader
	{
	private:
		const char* VertexPath;
		const char* FragmentPath;

	public:
		GLuint ShaderID;
		Shader(const char* vertexPath, const char* fragmentPath);
		~Shader();

		void Enable() const;
		void Disable() const;

	private:
		GLuint Load();
	};

} }