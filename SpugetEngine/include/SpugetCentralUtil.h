#pragma once

#ifdef _SPUGET_DLL_BUILD
	#define SPUGET_API __declspec(dllexport)
#else
	#define SPUGET_API __declspec(dllimport)
#endif



#ifdef _MYDEBUG
	#define LOG(x) std::cout << x << std::endl;
#else
	#define LOG(x)
#endif