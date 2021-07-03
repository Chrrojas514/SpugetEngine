#pragma once

#include <string>
#include <SpugetCentralUtil.h>

namespace Spuget
{
	class SPUGET_API Sprite
	{
	public:
		Sprite(const std::string& spriteFile);
		~Sprite();
		Sprite(const Sprite& copyConstructor) = delete;
		Sprite(Sprite&& moveConstructor) = delete;
		Sprite& operator==(const Sprite& assignmentOperator) = delete;
		Sprite& operator=(Sprite&& moveOperator) = delete;

		bool Load(const std::string& spriteFile);

		int GetWidth() const;
		int GetHeight() const;
		const unsigned char* GetImagePointer() const;

	private:
		unsigned char* mImage = nullptr;
		int mWidth = 0;
		int mHeight = 0;
		int mNumChannels = 0;
	};
}