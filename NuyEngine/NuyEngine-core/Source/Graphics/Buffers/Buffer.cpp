#include "Buffer.h"

namespace nuy { namespace graphics {

	Buffer::Buffer(GLfloat* data, GLsizei count, GLuint componentCount)
		: ComponentCount(componentCount)
	{
		glGenBuffers(1, &BufferID);
		glBindBuffer(GL_ARRAY_BUFFER, BufferID);
		glBufferData(GL_ARRAY_BUFFER, count * sizeof(GLfloat), data, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void Buffer::Bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, BufferID);
	}

	void Buffer::Unbind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

} }