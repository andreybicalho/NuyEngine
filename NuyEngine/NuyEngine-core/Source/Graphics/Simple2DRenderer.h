#pragma once

#include <deque>

#include "Renderer2D.h"
#include "StaticSprite.h"

namespace nuy {	namespace graphics {

	class Simple2DRenderer : public Renderer2D
	{
	private:
		std::deque<const StaticSprite*> RenderQueue;
	public:
		void Submit(const Renderable2D* renderable) override;
		void Draw() override;
	};

} }