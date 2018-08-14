#pragma once

#include "../Renderable2D.h"

namespace nuy { namespace graphics { 

	class Group : public Renderable2D
	{
	private:
		std::vector<Renderable2D*> Renderables;
		maths::Matrix4 TransformationMatrix;
	public:
		Group(const maths::Matrix4& transform);

		void Add(Renderable2D* renderable);
		void Submit(Renderer2D* renderer) const override;
	};

} }
