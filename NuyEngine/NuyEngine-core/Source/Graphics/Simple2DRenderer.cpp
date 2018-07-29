#include "Simple2DRenderer.h"

namespace nuy {	namespace graphics {

	

	void Simple2DRenderer::Submit(const Renderable2D* renderable)
	{
		RenderQueue.push_back(renderable);
	}

	void Simple2DRenderer::Flush()
	{
		while(!RenderQueue.empty())
		{
			const Renderable2D* renderable = RenderQueue.front();
			renderable->GetVAO()->Bind();
			renderable->GetIBO()->Bind();

			renderable->GetShader().SetUniformMat4("ml_matrix", maths::Matrix4::Translate(renderable->GetPosition()));
			glDrawElements(GL_TRIANGLES, renderable->GetIBO()->GetCount(), GL_UNSIGNED_SHORT, nullptr);

			renderable->GetIBO()->Unbind();
			renderable->GetVAO()->Unbind();

			RenderQueue.pop_front();
		}
	}

} }