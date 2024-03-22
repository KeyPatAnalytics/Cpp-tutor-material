#include <iostream>
#include "string_operation.cpp"
using namespace std;

int main() {
    // ˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜˜˜˜
    // ˜˜˜˜˜˜˜ ˜1
    const char* inputNumbers = "42 7 15 93 2";
    char* sortedNumbers = sortNumbersInString(inputNumbers);
    cout << "Sorted Numbers: " << sortedNumbers << endl;
    delete [] sortedNumbers;

    // ˜˜˜˜˜˜˜ ˜2
    const char* inputWords = "apple, banana, cherry, today, figure";
    size_t resultCount = 0;
    const char** wordsByLength = findWordsByLength(inputWords, 6, resultCount);
    cout << "Words of length 6: ";
    for (size_t i = 0; i < resultCount; ++i) {
        cout << wordsByLength[i] << " ";
        delete[] wordsByLength[i];  // ˜˜˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜
    }
    delete[] wordsByLength;
    cout << endl;

    // ˜˜˜˜˜˜˜ ˜3
    const char* inputText = "These are samples of text with few words.";
    char excludedChar = 's';
    const char* resultText = excludeWordsWithChar(inputText, excludedChar);
    cout << "Result after excluding words with '" << excludedChar << "': " << resultText << endl;
    delete[] resultText;  // ˜˜˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜

    return 0;
}
