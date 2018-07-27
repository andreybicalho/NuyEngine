#pragma once

#include <GL/glew.h>

namespace nuy { namespace graphics {

	class IndexBuffer
	{
	private:
		GLuint IndexBufferID;
		GLuint Count;
	public:
		IndexBuffer(GLushort* data, GLsizei count);

		void Bind() const;
		void Unbind() const;

		inline GLuint GetCount() const { return Count; }
	};

} }