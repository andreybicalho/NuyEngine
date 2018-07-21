#include "Shader.h"

#include <iostream>
#include <string>
#include <vector>

#include "../Utils/FileUtils.h"

namespace nuy { namespace graphics {

	Shader::Shader(const char* vertexPath, const char* fragmentPath)
		: VertexPath(vertexPath), FragmentPath(fragmentPath)
	{
		ShaderID = Load();
	}

	Shader::~Shader()
	{
		glDeleteProgram(ShaderID);
	}

	void Shader::SetUniform1i(const char* name, int value)
	{
		glUniform1i(GetUniformLocation(name), value);
	}
	
	void Shader::SetUniform1f(const char* name, float value)
	{
		glUniform1f(GetUniformLocation(name), value);
	}

	void Shader::SetUniform2f(const char* name, const nuy::maths::Vector2& vector)
	{
		glUniform2f(GetUniformLocation(name), vector.X, vector.Y);
	}

	void Shader::SetUniform3f(const char* name, const nuy::maths::Vector3& vector)
	{
		glUniform3f(GetUniformLocation(name), vector.X, vector.Y, vector.Z);
	}

	void Shader::SetUniform4f(const char* name, const nuy::maths::Vector4& vector)
	{
		glUniform4f(GetUniformLocation(name), vector.X, vector.Y, vector.Z, vector.W);
	}

	void Shader::SetUniformMat4(const char * name, const nuy::maths::Matrix4& matrix)
	{
		glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, matrix.elements);
	}

	void Shader::Enable() const
	{
		glUseProgram(ShaderID);
	}

	void Shader::Disable() const
	{
		glUseProgram(0);
	}

	GLuint Shader::Load()
	{
		GLuint programId = glCreateProgram();

		GLuint vertexId = glCreateShader(GL_VERTEX_SHADER);
		GLuint fragmentId = glCreateShader(GL_FRAGMENT_SHADER);

		std::string vertexSourceString = nuy::utils::FileUtils::ReadFile(VertexPath);
		std::string fragmentSourceString = nuy::utils::FileUtils::ReadFile(FragmentPath);

		const char* vertexSource = vertexSourceString.c_str();
		const char* framentSource = fragmentSourceString.c_str();

		glShaderSource(vertexId, 1, &vertexSource, NULL);
		glCompileShader(vertexId);

		GLint result;
		glGetShaderiv(vertexId, GL_COMPILE_STATUS, &result);
		if (result == GL_FALSE)
		{
			GLint length;
			glGetShaderiv(vertexId, GL_INFO_LOG_LENGTH, &length);
			std::vector<char> error(length);
			glGetShaderInfoLog(vertexId, length, &length, &error[0]);
			std::cout << "Failed to compile vertex shader!" << std:: endl << &error[0] << std::endl;
			glDeleteShader(vertexId);
			
			return 0;
		}

		glShaderSource(fragmentId, 1, &framentSource, NULL);
		glCompileShader(fragmentId);

		glGetShaderiv(fragmentId, GL_COMPILE_STATUS, &result);
		if (result == GL_FALSE)
		{
			GLint length;
			glGetShaderiv(fragmentId, GL_INFO_LOG_LENGTH, &length);
			std::vector<char> error(length);
			glGetShaderInfoLog(fragmentId, length, &length, &error[0]);
			std::cout << "Failed to compile fragment shader!" << std::endl << &error[0] << std::endl;
			glDeleteShader(fragmentId);

			return 0;
		}

		glAttachShader(programId, vertexId);
		glAttachShader(programId, fragmentId);

		glLinkProgram(programId);
		glValidateProgram(programId);

		glDeleteShader(vertexId);
		glDeleteShader(fragmentId);

		return programId;
	}

	GLint Shader::GetUniformLocation(const GLchar* name)
	{
		return glGetUniformLocation(ShaderID, name);
	}

} }