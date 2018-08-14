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

#include "Graphics/Layers/Group.h"

#define TEST_50K_SPRITES 0

using namespace nuy::graphics;
using namespace nuy::maths;

int main()
{
	Window window("Nuy Engine", 960, 540);

	Matrix4 ortho = Matrix4::Orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f); // 16x9 space hence 16:9 aspect ratio

	Shader* s = new Shader("Source/Resources/vertexShader.shader", "Source/Resources/fragmentShader.shader");
	Shader* s2 = new Shader("Source/Resources/vertexShader.shader", "Source/Resources/fragmentShader.shader");
	Shader& shader = *s;
	Shader& shader2 = *s2;
	shader.Enable();
	shader2.Enable();

	shader.SetUniform2f("in_light_pos", Vector2(0.0f, 0.0f));
	shader2.SetUniform2f("in_light_pos", Vector2(0.0f, 0.0f));

	TileLayer layer(&shader);

#if TEST_50K_SPRITES
	for (float y = -9.0f; y < 9.0f; y += 0.1f)
	{
		for (float x = -16.0f; x < 16.0f; x += 0.1f)
		{
			layer.Add(new Sprite(x, y, 0.09f, 0.09f, Vector4(rand() % 1000 / 1000.0f, 0, 1, 1)));
		}
	}
#else
	for (float y = -9.0f; y < 9.0f; y++)
	{
		for (float x = -16.0f; x < 16.0f; x++)
		{
			layer.Add(new Sprite(x, y, 0.9f, 0.9f, Vector4(rand() % 1000 / 1000.0f, 0, 1, 1)));
		}
	}
	
	Matrix4 transform = Matrix4::Translate(Vector3(-15.0f, 5.0f, 0.0f)) * Matrix4::Rotate(45.0f, Vector3(0, 0, 1));
	Group* group = new Group(transform);
	group->Add(new Sprite(0, 0, 6, 3, Vector4(1, 1, 1, 1)));
	
	Group* button = new Group(Matrix4::Translate(Vector3(1.5f, 2.5f, 0.0f)));
	button->Add(new Sprite(0, 0, 5.0f, 2.0f, Vector4(1, 0, 1, 1)));
	button->Add(new Sprite(0.5f, 0.5f, 3.0f, 1.0f, Vector4(0.2f, 0.3f, 0.8f, 1)));
	group->Add(button);

	layer.Add(group);
#endif


	TileLayer layer2(&shader2);
	layer2.Add(new Sprite(-2, 2, 4, 4, Vector4(0, 1, 1, 1)));

	nuy::Timer timer;
	float time = 0.0f;
	unsigned int framesPerSecond = 0;

	while (!window.IsClosed())
	{
		window.Clear();

		// our cool light position
		double x, y;
		window.GetMousePosition(x, y);
		shader.Enable();
		shader.SetUniform2f("in_light_pos", Vector2((float)(x * 32.0f / 960.0f - 16.0f), (float)(9.0f - y * 18.0f / 540.0f)));
		shader2.Enable();
		shader2.SetUniform2f("in_light_pos", Vector2(-8, -3));

		// our cool animation
		Matrix4 mat = Matrix4::Translate(Vector3(2, 2, 5));
		mat = mat * Matrix4::Rotate(timer.Elapsed() * 100.f, Vector3(0, 0, 1));
		mat = mat * Matrix4::Translate(Vector3(-5, -5, -5));
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