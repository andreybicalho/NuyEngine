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

} }