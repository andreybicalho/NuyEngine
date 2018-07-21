#pragma once

#include <GL/glew.h>

#include "../Maths/Vector2.h"
#include "../Maths/Vector3.h"
#include "../Maths/Vector4.h"
#include "../Maths/Matrix4.h"

namespace nuy { namespace graphics {
	
	class Shader
	{
	private:
		GLuint ShaderID;
		const char* VertexPath;
		const char* FragmentPath;

	public:
		Shader(const char* vertexPath, const char* fragmentPath);
		~Shader();

		void SetUniform1i(const char* name, int value);
		void SetUniform1f(const char* name, float value);
		void SetUniform2f(const char* name, const nuy::maths::Vector2& vector);
		void SetUniform3f(const char* name, const nuy::maths::Vector3& vector);
		void SetUniform4f(const char* name, const nuy::maths::Vector4& vector);
		void SetUniformMat4(const char* name, const nuy::maths::Matrix4& matrix);

		void Enable() const;
		void Disable() const;

	private:
		GLuint Load();
		GLint GetUniformLocation(const GLchar* name);
	};

} }