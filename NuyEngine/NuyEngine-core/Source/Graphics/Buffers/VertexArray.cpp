#include "VertexArray.h"

namespace nuy { namespace graphics {


	VertexArray::VertexArray()
	{
		glGenVertexArrays(1, &VertexArrayID);
	}

	VertexArray::~VertexArray()
	{
		for (int i = 0; i < Buffers.size(); i++)
		{
			delete Buffers[i];
		}

		glDeleteVertexArrays(1, &VertexArrayID);
	}

	void VertexArray::AddBuffer(Buffer* buffer, GLuint index)
	{
		Bind();
		buffer->Bind();
		
		Buffers.push_back(buffer);

		glEnableVertexAttribArray(index);
		glVertexAttribPointer(index, buffer->GetComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);

		buffer->Unbind();
		Unbind();
	}

	void VertexArray::Bind() const
	{
		glBindVertexArray(VertexArrayID);
	}

	void VertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}

} }