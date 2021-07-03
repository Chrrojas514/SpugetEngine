#pragma once
#include <SpugetCentralUtil.h>
#include "Window.h"

namespace Spuget
{
	class SPUGET_API SpugetApplication
	{
	public:
		void RunGame();
		static SpugetApplication* GetApplication();   //Static because we want to access without creating obj
		static void Init();
		virtual ~SpugetApplication();

		static int GetWindowWidth();
		static int GetWindowHeight();
	private:
		SpugetApplication(); //Private contructor because we want this to be a singleton

		inline static SpugetApplication* instance{ nullptr }; //inline keyword - lets us declare static here(?)
		Spuget::Window* window{ nullptr };
	};
}