#pragma once

#include <Gl/glew.h>

#include "../Maths/Maths.h"
#include "Renderable2D.h"

namespace nuy {	namespace graphics {

	class Renderer2D
	{
	protected:
		std::vector<nuy::maths::Matrix4> TransformationStack;
		const maths::Matrix4* TransformationBack;
	protected:
		Renderer2D()
		{
			TransformationStack.push_back(nuy::maths::Matrix4::Identity());
			TransformationBack = &TransformationStack.back();
		}
	public:
		virtual void Begin() {}
		virtual void Submit(const Renderable2D* renderable) = 0;
		virtual void End() {}
		virtual void Draw() = 0;

		void Push(const nuy::maths::Matrix4& matrix, bool override = false)
		{
			if(override)
			{ 
				TransformationStack.push_back(matrix);
			}
			else
			{
				TransformationStack.push_back(TransformationStack.back() * matrix);
			}

			TransformationBack = &TransformationStack.back();
		}

		void Pop()
		{
			if (TransformationStack.size() > 1)
			{
				// TODO(andrey): log this!
				TransformationStack.pop_back();

				TransformationBack = &TransformationStack.back();
			}
		}
	};

} }