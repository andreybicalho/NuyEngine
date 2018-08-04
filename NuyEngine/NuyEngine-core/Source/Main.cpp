#include <iostream>

#include "Maths/Maths.h"
#include "Graphics/Window.h"
#include "Graphics/Shader.h"
#include "Graphics/Buffers/Buffer.h"
#include "Graphics/Buffers/IndexBuffer.h"
#include "Graphics/Buffers/VertexArray.h"

#include "Graphics/Renderable2D.h"
#include "Graphics/Simple2DRenderer.h"
#include "Graphics/BatchRenderer2D.h"

#include "Graphics/StaticSprite.h"
#include "Graphics/Sprite.h"

#define BATCH_RENDERER 1

int main()
{
	nuy::graphics::Window window("Nuy Engine", 960, 540);

	nuy::maths::Matrix4 ortho = nuy::maths::Matrix4::Orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f); // 16x9 space hence 16:9 aspect ratio

	nuy::graphics::Shader shader("Source/Resources/vertexShader.shader", "Source/Resources/fragmentShader.shader");
	shader.Enable();
	shader.SetUniformMat4("pr_matrix", ortho);

#if BATCH_RENDERER
	nuy::graphics::Sprite sprite(3, 3, 4, 4, nuy::maths::Vector4(1, 0, 1, 1));
	nuy::graphics::Sprite sprite2(1, 1, 2, 3, nuy::maths::Vector4(0.2f, 0, 1, 1));
	nuy::graphics::BatchRenderer2D renderer;
#else
	nuy::graphics::StaticSprite sprite(3, 3, 4, 4, nuy::maths::Vector4(1, 0, 1, 1), shader);
	nuy::graphics::StaticSprite sprite2(1, 1, 2, 3, nuy::maths::Vector4(0.2f, 0, 1, 1), shader);
	nuy::graphics::Simple2DRenderer renderer;
#endif
	shader.SetUniform2f("in_light_pos", nuy::maths::Vector2(0.0f, 0.0f));
	shader.SetUniform4f("in_color", nuy::maths::Vector4(0.2f, 0.1f, 0.0f, 1.0f));

	while (!window.IsClosed())
	{
		window.Clear();
		double x, y;
		window.GetMousePosition(x, y);
		shader.SetUniform2f("in_light_pos", nuy::maths::Vector2((float)(x * 16.0f / 960.0f), (float)(9.0f - y * 9.0f / 540.0f)));
		//std::cout << x << ", " << y << std::endl;
#if BATCH_RENDERER
		renderer.Begin();
#endif
		renderer.Submit(&sprite);
		renderer.Submit(&sprite2);
#if BATCH_RENDERER
		renderer.End();
#endif
		renderer.Draw();

		window.Update();
	}



	return 0;
}