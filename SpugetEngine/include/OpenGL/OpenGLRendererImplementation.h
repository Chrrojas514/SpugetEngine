#pragma once

#include <RendererImplementation.h>
#include <OpenGL/OpenGLShader.h>

namespace Spuget
{
	class OpenGLRendererImplementation : public RendererImplementation
	{
	public:
		OpenGLRendererImplementation();
		virtual void Init() override;
		virtual void Draw(const Sprite& image, int xCoord, int yCoord, int imageWidth, int imageHeight) override;
		virtual ~OpenGLRendererImplementation();

	private:
		OpenGLShader mDefaultShaders;
	};
}