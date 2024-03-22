#pragma once

#ifdef STRUCTS_EXPORTS
#define STRUCTS_API __declspec(dllexport)

#else
#define STRUCTS_API __declspec(dllimport)

#endif // STRUCTS_EXPORTS
