#pragma once

#include <Gl/glew.h>

#include "../Maths/Maths.h"
#include "Renderable2D.h"

namespace nuy {	namespace graphics {

	class Renderer2D
	{
	public:
		virtual void Begin() {}
		virtual void Submit(const Renderable2D* renderable) = 0;
		virtual void End() {}
		virtual void Draw() = 0;
	};

} }