#pragma once

#include "Renderable2D.h"

namespace nuy { namespace graphics {

    class Sprite : public Renderable2D
    {
	public:
		Sprite(float x, float y, float width, float height, maths::Vector4& color);
    };

} }