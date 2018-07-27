#pragma once

#include <vector>
#include <GL/glew.h>

#include "Buffer.h"

namespace nuy { namespace graphics {

	class VertexArray
	{
	private:
		GLuint VertexArrayID;
		std::vector<Buffer*> Buffers;
	public:
		VertexArray();
		~VertexArray();

		void AddBuffer(Buffer* buffer, GLuint index);

		void Bind() const;
		void Unbind() const;

	};

} }