#pragma once

#ifdef TASK7_EXPORTS
#define TASK7_API __declspec(dllexport)

#else
#define TASK7_API __declspec(dllimport)

#endif // TASK7_EXPORTS