#include "TileLayer.h"

namespace nuy { namespace graphics { 

	TileLayer::TileLayer(Shader* shader)
		: Layer(new BatchRenderer2D(), shader, maths::Matrix4::Orthographic(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f))
	{
	}

	TileLayer::~TileLayer()
	{
	}

} }