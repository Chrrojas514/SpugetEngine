#include <pch.h>
#include "SpugetApplication.h"
#include "Renderer.h"
#include "Sprite.h"
#include "WinWindows.h"

namespace Spuget
{
	void SpugetApplication::RunGame()
	{
		LOG("Starting the game")

		Renderer::Init();

		Sprite testOne{ "../SpugetEngine/assets/Sprites/unknown.png" };
		Sprite testTwo{ "../SpugetEngine/assets/Sprites/fish.png" };

		while (true)
		{
			Renderer::Draw(testOne, 100, 100, testOne.GetWidth(), testOne.GetHeight());
			Renderer::Draw(testTwo, 100, 100, testTwo.GetWidth(), testTwo.GetHeight());

			window->SwapBuffers();
			window->PollForEvents();
		}
	}

	SpugetApplication* SpugetApplication::GetApplication()
	{
		return instance;
	}

	void SpugetApplication::Init()
	{
		if (instance == nullptr)
			instance = new SpugetApplication;
	}

	SpugetApplication::SpugetApplication()
	{
		assert(instance == nullptr);

#ifdef _SPUGET_WINDOWS
		window = new WinWindows;
#else
	#Only_Windows_Supported_for_Now
#endif

		bool success{ window->CreateWindow(800,600) };
		assert(success);
	}

	SpugetApplication::~SpugetApplication()
	{
		window->DeleteWindow();
	}

	int SpugetApplication::GetWindowWidth()
	{
		return instance->window->GetWidth();
	}

	int SpugetApplication::GetWindowHeight()
	{
		return instance->window->GetHeight();
	}
}