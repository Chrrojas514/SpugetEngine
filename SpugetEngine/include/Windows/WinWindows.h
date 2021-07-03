#pragma once

#include "SpugetCentralUtil.h"
#include "Window.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "glad/glad.h"

namespace Spuget
{
	class WinWindows final : public Spuget::Window
	{
	public:
		virtual bool CreateWindow(unsigned int width, unsigned int height) override;
		virtual void DeleteWindow() override;
		virtual void SwapBuffers() override;
		virtual void PollForEvents() override;
		
		virtual int GetWidth() const override;
		virtual int GetHeight() const override;

	private:
		GLFWwindow* application_window;
	};
}