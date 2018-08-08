#pragma once

#include "Buffers/Buffer.h"
#include "Buffers/IndexBuffer.h"
#include "Buffers/VertexArray.h"

#include "../Maths/Maths.h"
#include "Shader.h"

namespace nuy {	namespace graphics {

	struct VertexData
	{
		maths::Vector3 vertex;
		//maths::Vector4 color;
		unsigned int color;
	};

	class Renderable2D
	{
	protected:
		maths::Vector3 Position;
		maths::Vector2 Size;
		maths::Vector4 Color;
	
	public:
		Renderable2D(maths::Vector3 position, maths::Vector2 size, maths::Vector4 color)
			: Position(position), Size(size), Color(color)
		{ }

		virtual ~Renderable2D() { }

		inline const maths::Vector3& GetPosition() const { return Position; }
		inline const maths::Vector2& GetSize() const { return Size; }
		inline const maths::Vector4& GetColor() const { return Color; }
	};

} }