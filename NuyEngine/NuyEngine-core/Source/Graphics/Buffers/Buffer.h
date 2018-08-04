#pragma once

#include <GL/glew.h>

namespace nuy { namespace graphics {

	class Buffer
	{
	private:
		GLuint BufferID;
		GLuint ComponentCount;
	public:
		Buffer(GLfloat* data, GLsizei count, GLuint componentCount);
		~Buffer();

		void Bind() const;
		void Unbind() const;

		inline GLuint GetComponentCount() const { return ComponentCount; }
	};

} }