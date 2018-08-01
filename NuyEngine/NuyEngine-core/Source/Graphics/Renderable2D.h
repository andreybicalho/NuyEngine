#pragma once

#include "Buffers/Buffer.h"
#include "Buffers/IndexBuffer.h"
#include "Buffers/VertexArray.h"

#include "../Maths/Maths.h"
#include "Shader.h"

namespace nuy {	namespace graphics {

	class Renderable2D
	{
	protected:
		maths::Vector3 Position;
		maths::Vector2 Size;
		maths::Vector4 Color;

		VertexArray* _VertexArray;
		Buffer* VertexBuffer;
		Buffer* ColorBuffer;
		IndexBuffer* _IndexBuffer;

		Shader& _Shader;
	
	public:
		Renderable2D(maths::Vector3 position, maths::Vector2 size, maths::Vector4 color, Shader& shader)
			: Position(position), Size(size), Color(color), _Shader(shader)
		{
			_VertexArray = new VertexArray();
			GLfloat vertices[] = 
			{
				0,      0,      0,
				0,      size.Y, 0,
				size.X, size.Y, 0,
				size.X, 0,      0
			};

			GLfloat colors[] =
			{
				color.X, color.Y, color.Z, color.W,
				color.X, color.Y, color.Z, color.W,
				color.X, color.Y, color.Z, color.W,
				color.X, color.Y, color.Z, color.W
			};

			_VertexArray->AddBuffer(new Buffer(vertices, 4 * 3, 3), 0);
			_VertexArray->AddBuffer(new Buffer(colors, 4 * 4, 4), 1);

			GLushort indices[] =
			{
				0, 1, 2, 
				0, 2, 3
			};

			_IndexBuffer = new IndexBuffer(indices, 6);
		}

		virtual ~Renderable2D()
		{
			delete _VertexArray;
			delete _IndexBuffer;
		}

		inline const VertexArray* GetVAO() const { return _VertexArray; }
		inline const IndexBuffer* GetIBO() const { return _IndexBuffer; }

		inline Shader& GetShader() const { return _Shader; }

		inline const maths::Vector3& GetPosition() const { return Position; }
		inline const maths::Vector2& GetSize() const { return Size; }
		inline const maths::Vector4& GetColor() const { return Color; }
	};

} }