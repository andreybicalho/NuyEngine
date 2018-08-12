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

#include "Utils/Timer.h"

#include <time.h>

#include "Graphics/Layers/TileLayer.h"

#define BATCH_RENDERER 1

int main()
{
	nuy::graphics::Window window("Nuy Engine", 960, 540);

	nuy::maths::Matrix4 ortho = nuy::maths::Matrix4::Orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f); // 16x9 space hence 16:9 aspect ratio

	nuy::graphics::Shader* s = new nuy::graphics::Shader("Source/Resources/vertexShader.shader", "Source/Resources/fragmentShader.shader");
	nuy::graphics::Shader* s2 = new nuy::graphics::Shader("Source/Resources/vertexShader.shader", "Source/Resources/fragmentShader.shader");
	nuy::graphics::Shader& shader = *s;
	nuy::graphics::Shader& shader2 = *s2;
	shader.Enable();
	shader2.Enable();

	shader.SetUniform2f("in_light_pos", nuy::maths::Vector2(0.0f, 0.0f));
	shader2.SetUniform2f("in_light_pos", nuy::maths::Vector2(0.0f, 0.0f));


	nuy::graphics::TileLayer layer(&shader);
	for (float y = -9.0f; y < 9.0f; y += 0.1f)
	{
		for (float x = -16.0f; x < 16.0f; x += 0.1f)
		{
			layer.Add(new nuy::graphics::Sprite(x, y, 0.09f, 0.09f, nuy::maths::Vector4(rand() % 1000 / 1000.0f, 0, 1, 1)));
		}
	}


	nuy::graphics::TileLayer layer2(&shader2);
	layer2.Add(new nuy::graphics::Sprite(-2, 2, 4, 4, nuy::maths::Vector4(1, 0, 1, 1)));

	nuy::Timer timer;
	float time = 0.0f;
	unsigned int framesPerSecond = 0;;
	while (!window.IsClosed())
	{
		window.Clear();

		// our cool light position
		double x, y;
		window.GetMousePosition(x, y);
		shader.Enable();
		shader.SetUniform2f("in_light_pos", nuy::maths::Vector2(-8, -3));
		shader2.Enable();
		shader2.SetUniform2f("in_light_pos", nuy::maths::Vector2((float)(x * 32.0f / 960.0f - 16.0f), (float)(9.0f - y * 18.0f / 540.0f)));

		// our cool animation
		nuy::maths::Matrix4 mat = nuy::maths::Matrix4::Translate(nuy::maths::Vector3(2, 2, 5));
		mat = mat * nuy::maths::Matrix4::Rotate(timer.Elapsed() * 100.f, nuy::maths::Vector3(0, 0, 1));
		mat = mat * nuy::maths::Matrix4::Translate(nuy::maths::Vector3(-5, -5, -5));
		shader.SetUniformMat4("ml_matrix", mat);
		//

		layer.Render();
		layer2.Render();

		window.Update();
		framesPerSecond++;
		if((timer.Elapsed() - time) > 1.0f)
		{ 
			time += 1.0f;
			printf("%d fps\n", framesPerSecond);
			framesPerSecond = 0;
		}

	}



	return 0;
}