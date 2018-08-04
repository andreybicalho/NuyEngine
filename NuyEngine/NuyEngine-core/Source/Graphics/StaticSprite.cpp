#include "StaticSprite.h"

namespace nuy { namespace graphics {

	StaticSprite::StaticSprite(float x, float y, float width, float height, maths::Vector4& color, Shader& shader)
        : Renderable2D(maths::Vector3(x, y, 0), maths::Vector2(width, height), color), _Shader(shader)
	{
		_VertexArray = new VertexArray();
		GLfloat vertices[] =
		{
			0,      0,      0,
			0,      height, 0,
			width,  height, 0,
			width,  0,      0
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

	StaticSprite::~StaticSprite()
	{
        delete _VertexArray;
		delete _IndexBuffer;
	}    

} }