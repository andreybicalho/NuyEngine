#pragma once

#include "../Renderer2D.h"
#include "../Renderable2D.h"

namespace nuy { namespace graphics { 

	class Layer
	{
	protected:
		Renderer2D* Renderer;
		std::vector<Renderable2D*> Renderables;
		Shader* _Shader;
		maths::Matrix4 ProjectionMatrix;	
	protected:
		Layer(Renderer2D* renderer, Shader* shader, maths::Matrix4 projectionMatrix);
	public:
		virtual ~Layer();
		virtual void Add(Renderable2D* renderable);
		virtual void Render();
	};

} }
