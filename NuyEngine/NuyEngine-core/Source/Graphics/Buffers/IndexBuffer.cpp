#include "IndexBuffer.h"

namespace nuy { namespace graphics {

	IndexBuffer::IndexBuffer(GLushort* data, GLsizei count)
		: Count(count)
	{
		glGenBuffers(1, &IndexBufferID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexBufferID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLushort), data, GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	IndexBuffer::IndexBuffer(GLuint* data, GLsizei count)
		: Count(count)
	{
		glGenBuffers(1, &IndexBufferID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexBufferID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), data, GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	IndexBuffer::~IndexBuffer()
	{
		glDeleteBuffers(1, &IndexBufferID);
	}

	void IndexBuffer::Bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexBufferID);
	}

	void IndexBuffer::Unbind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

} }