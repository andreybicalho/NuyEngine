#pragma once

#include <deque>

#include "Renderer2D.h"

namespace nuy {	namespace graphics {

	class Simple2DRenderer : public Renderer2D
	{
	private:
		std::deque<const Renderable2D*> RenderQueue;
	public:
		void Submit(const Renderable2D* renderable) override;
		void Flush() override;
	};

} }