#pragma once
#ifdef TASK2_EXPORTS
	#define TASK2_API __declspec(dllexport)
#else
	#define TASK2_API __declspec(dllimport)
#endif
