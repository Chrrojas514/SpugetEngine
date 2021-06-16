#include <pch.h>
#include "SpugetApplication.h"

namespace Spuget
{
	void SpugetApplication::RunGame()
	{
		LOG("Starting the game")

		while (true)
		{

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

	SpugetApplication::~SpugetApplication()
	{
		
	}

	SpugetApplication::SpugetApplication()
	{
		assert(instance == nullptr);
	}
}