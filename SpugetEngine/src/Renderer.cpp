#include <pch.h>
#include <Renderer.h>
#include <OpenGL\OpenGLRendererImplementation.h>

namespace Spuget
{
	void Renderer::Init()
	{
		if (instance == nullptr)
			instance = new Renderer;
	}

	void Renderer::ShutDown()
	{
		if (instance != nullptr)
			delete instance;
	}

	void Renderer::Draw(const Sprite& image, int xCoord, int yCoord, int imageWidth, int imageHeight)
	{
		assert(instance != nullptr);

		instance->mDrawEngine->Draw(image, xCoord, yCoord, imageWidth, imageHeight);
	}

	Renderer::Renderer()
	{
	#ifdef _SPUGET_OPENGL
		mDrawEngine = new OpenGLRendererImplementation;
	#else
		#only_opengl_supported_FOR_NOW
	#endif
	}
}