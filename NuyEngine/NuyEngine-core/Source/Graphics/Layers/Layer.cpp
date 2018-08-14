#include "Layer.h"

namespace nuy { namespace graphics { 

	Layer::Layer(Renderer2D* renderer, Shader* shader, maths::Matrix4 projectionMatrix)
		: Renderer(renderer), _Shader(shader), ProjectionMatrix(projectionMatrix)
	{
		_Shader->Enable();
		_Shader->SetUniformMat4("pr_matrix", ProjectionMatrix);
		_Shader->Disable();
	}

	Layer::~Layer()
	{
		delete _Shader;
		delete Renderer;
		for (int i = 0; i < Renderables.size(); i++) 
		{ 
			delete Renderables[i];
		}
	}

	void Layer::Add(Renderable2D* renderable)
	{
		Renderables.push_back(renderable);
	}

	void Layer::Render()
	{
		_Shader->Enable();

		Renderer->Begin();
		for (const Renderable2D* renderable : Renderables)
		{
			renderable->Submit(Renderer);
		}
		Renderer->End();
		Renderer->Draw();
	}

} }