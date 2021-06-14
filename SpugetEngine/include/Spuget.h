#pragma once

#include <SpugetCentralUtil.h>
#include <SpugetApplication.h>

#define START_GAME(class_name)							\
	int main()											\
	{													\
		class_name::Init();								\
		class_name::GetApplication()->RunGame();		\
	}