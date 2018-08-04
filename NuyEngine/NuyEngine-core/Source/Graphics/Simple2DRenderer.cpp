#include "Simple2DRenderer.h"

namespace nuy {	namespace graphics {

	void Simple2DRenderer::Submit(const Renderable2D* renderable)
	{
		// TODO(andrey): throw an exception, log it or scream, if this renderable is not a StaticSprite
		RenderQueue.push_back( (StaticSprite*) renderable);
	}

	void Simple2DRenderer::Draw()
	{
		while(!RenderQueue.empty())
		{
			const StaticSprite* staticSprite = RenderQueue.front();
			staticSprite->GetVAO()->Bind();
			staticSprite->GetIBO()->Bind();

			staticSprite->GetShader().SetUniformMat4("ml_matrix", maths::Matrix4::Translate(staticSprite->GetPosition()));
			glDrawElements(GL_TRIANGLES, staticSprite->GetIBO()->GetCount(), GL_UNSIGNED_SHORT, nullptr);

			staticSprite->GetIBO()->Unbind();
			staticSprite->GetVAO()->Unbind();

			RenderQueue.pop_front();
		}
	}

} }