#include <iostream>

#include "Maths/Maths.h"
#include "Graphics/Window.h"
#include "Graphics/Shader.h"
#include "Graphics/Buffers/Buffer.h"
#include "Graphics/Buffers/IndexBuffer.h"
#include "Graphics/Buffers/VertexArray.h"

#include "Graphics/Renderable2D.h"
#include "Graphics/Simple2DRenderer.h"

#include "Graphics/StaticSprite.h"
#include "Graphics/Sprite.h"

int main()
{
	nuy::graphics::Window window("Nuy Engine", 960, 540);

	nuy::maths::Matrix4 ortho = nuy::maths::Matrix4::Orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f); // 16x9 space hence 16:9 aspect ratio

	nuy::graphics::Shader shader("Source/Resources/vertexShader.shader", "Source/Resources/fragmentShader.shader");
	shader.Enable();
	shader.SetUniformMat4("pr_matrix", ortho);

	nuy::graphics::StaticSprite staticSprite(3, 3, 4, 4, nuy::maths::Vector4(1, 0, 1, 1), shader);
	nuy::graphics::StaticSprite staticSprite2(1, 1, 2, 3, nuy::maths::Vector4(0.2f, 0, 1, 1), shader);
	nuy::graphics::Simple2DRenderer renderer;

	shader.SetUniform2f("in_light_pos", nuy::maths::Vector2(0.0f, 0.0f));
	shader.SetUniform4f("in_color", nuy::maths::Vector4(0.2f, 0.1f, 0.0f, 1.0f));

	while (!window.IsClosed())
	{
		window.Clear();
		double x, y;
		window.GetMousePosition(x, y);
		shader.SetUniform2f("in_light_pos", nuy::maths::Vector2((float)(x * 16.0f / 960.0f), (float)(9.0f - y * 9.0f / 540.0f)));
		//std::cout << x << ", " << y << std::endl;

		renderer.Submit(&staticSprite);
		renderer.Submit(&staticSprite2);
		renderer.Draw();

		window.Update();
	}



	return 0;
}