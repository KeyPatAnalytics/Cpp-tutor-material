#ifndef STRING_OPERATIONS_H
#define STRING_OPERATIONS_H

#include <vector>

char* sortNumbersInString(const char* input);
const char** findWordsByLength(const char* input, int m, size_t& resultCount);
const char* excludeWordsWithChar(const char* input, char excludedChar);

#endif // STRING_OPERATIONS_H
