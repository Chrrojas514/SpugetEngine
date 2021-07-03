#include <pch.h>
#include <SpugetApplication.h>
#include <OpenGL/OpenGLRendererImplementation.h>

namespace Spuget
{
	OpenGLRendererImplementation::OpenGLRendererImplementation()
	{
		Init();
	}

	void OpenGLRendererImplementation::Init()
	{
		mDefaultShaders.Load(
			"../SpugetEngine/assets/shaders/VertexShaderDefault.glsl",
			"../SpugetEngine/assets/shaders/FragmentShaderDefault.glsl"
		);

		mDefaultShaders.Use();

		glEnable(GL_BLEND);

		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	void OpenGLRendererImplementation::Draw(const Sprite& image, int xCoord, int yCoord, int imageWidth, int imageHeight)
	{
		float vertices[] = {
			(float)xCoord				, (float)yCoord				   , 0.0f, 0.0f,
			(float)xCoord				, (float)(yCoord + imageHeight), 0.0f, 1.0f,
			(float)(xCoord + imageWidth), (float)(yCoord)			   , 1.0f, 0.0f,
			(float)(xCoord + imageWidth), (float)(yCoord + imageHeight), 1.0f, 1.0f
		};

		unsigned int VBO, VAO;

		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
		glEnableVertexAttribArray(1);

		unsigned int picture;

		glGenTextures(1, &picture);
		glBindTexture(GL_TEXTURE_2D, picture);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imageWidth, imageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, image.GetImagePointer());

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		mDefaultShaders.SetVec2Int("windowSize", SpugetApplication::GetWindowWidth(), SpugetApplication::GetWindowHeight());

		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	}

	OpenGLRendererImplementation::~OpenGLRendererImplementation() {}
}