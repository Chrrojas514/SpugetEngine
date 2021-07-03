#include <pch.h>
#include "Windows/WinWindows.h"

namespace Spuget
{
	bool WinWindows::CreateWindow(unsigned int width, unsigned int height)
	{
		glfwInit();
		
		application_window = glfwCreateWindow(width, height, "Spuget Engine", NULL, NULL);

		if (application_window == nullptr)
			return false;

		glfwMakeContextCurrent(application_window);
		gladLoadGL();

		glfwSwapInterval(1);

		return true;
	}

	void WinWindows::DeleteWindow()
	{
		glfwDestroyWindow(application_window);
		glfwTerminate();
	}

	void WinWindows::SwapBuffers()
	{
		glfwSwapBuffers(application_window);
	}

	void WinWindows::PollForEvents()
	{
		glfwPollEvents();
	}

	int WinWindows::GetWidth() const
	{
		int width = 0;
		int height = 0;
		glfwGetWindowSize(application_window, &width, &height);

		return width;
	}

	int WinWindows::GetHeight() const
	{
		int width = 0;
		int height = 0;
		glfwGetWindowSize(application_window, &width, &height);

		return height;
	}
}