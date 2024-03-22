#pragma once
#include "Task2Api.hpp"
#include <iostream>

using namespace std;

TASK2_API pair<double, int> Taylor(float x, double eps);
TASK2_API void PrintResult(float a, float , float dx);
