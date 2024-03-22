#pragma once

#ifdef TASK3_EXPORTS
	#define TASK3API __declspec(dllexport)
#else
	#define TASK3API __declspec(dllimport)
#endif // TASK3_EXPORTS
