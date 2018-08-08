#pragma once

#include <cstddef>

#include "Renderer2D.h"
#include "Buffers/VertexArray.h"
#include "Buffers/IndexBuffer.h"

namespace nuy { namespace graphics {

#define RENDERER_MAX_SPRITES	60000
#define RENDERER_VERTEX_SIZE	sizeof(VertexData)
#define RENDERER_SPRITE_SIZE	RENDERER_VERTEX_SIZE * 4 /* sprites have 4 vertices */
#define RENDERER_BUFFER_SIZE	RENDERER_SPRITE_SIZE * RENDERER_MAX_SPRITES
#define RENDERER_INDICES_SIZE	RENDERER_MAX_SPRITES * 6 /* sprites have 6 indices */

#define SHADER_VERTEX_INDEX 0
#define SHADER_COLOR_INDEX  1

	class BatchRenderer2D : public Renderer2D
	{
	private:
		GLuint VAO_ID;
		GLuint VBO_ID;
		IndexBuffer* IBO;
		GLsizei IndexCount;
		VertexData* _Buffer;
	public:
		BatchRenderer2D();
		~BatchRenderer2D();

		void Begin();
		void Submit(const Renderable2D* renderable) override;
		void End();
		void Draw() override;
	private:
		void Init();
	};

} }