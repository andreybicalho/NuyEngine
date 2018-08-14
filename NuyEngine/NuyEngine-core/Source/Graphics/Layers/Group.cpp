#include "Group.h"

namespace nuy { namespace graphics { 

	Group::Group(const maths::Matrix4& transform)
		: TransformationMatrix(transform)
	{
	}

	void Group::Add(Renderable2D* renderable)
	{
		Renderables.push_back(renderable);
	}

	void Group::Submit(Renderer2D* renderer) const
	{
		renderer->Push(TransformationMatrix);

		for (const Renderable2D* renderable : Renderables)
		{
			renderable->Submit(renderer);
		}

		renderer->Pop();
	}

} }