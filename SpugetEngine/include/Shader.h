#pragma once

#include "SpugetCentralUtil.h"
#include <pch.h>

namespace Spuget
{
	class SPUGET_API Shader
	{
	public:
		virtual bool Load(const std::string &vertexFile, const std::string &fragmentFile) = 0;
		virtual void Use() = 0;

		virtual void SetVec2Int(const std::string& uniformName, int valueOne, int valueTwo) = 0;
		virtual ~Shader() = 0 {};
	};
}