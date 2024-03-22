#include <iostream>
#include <cstddef> // Для size_t
#include <cstdlib> // Для atoi
#include <algorithm> // Для std::swap
#include "string_operation.h"

// Функция, вычисляющая длину строки
size_t my_strlen(const char* str) {
    if (str == nullptr) {
        return 0;
    }

    // Подсчет длины
    size_t length = 0;
    while (str[length] != '\0') {
        ++length;
    }

    return length;
}

// Проверка, является ли символ разделителем
bool isSeparator(char c) {
    return (c == ' ' || c == ',' || c == '\0');
}

// Сравнение для собственной функции сортировки
bool compareIntegers(int a, int b) {
    return a > b; // Смените знак для сортировки в порядке возрастания
}

// Собственная функция сортировки (bubble sort)
void sortArray(int* arr, size_t size, bool (*compare)(int, int)) {
    for (size_t i = 0; i < size - 1; ++i) {
        for (size_t j = 0; j < size - i - 1; ++j) {
            if (compare(arr[j], arr[j + 1])) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// ЗАДАНИЕ №1
// Сортировка чисел в строке и возврат упорядоченной C-строки
char* sortNumbersInString(const char* input) {
    // Подсчет количества чисел
    size_t numCount = 0;
    size_t currentIndex = 0;

    while (input[currentIndex] != '\0') {
        while (!isSeparator(input[currentIndex])) {
            currentIndex++;
        }
        numCount++;
        if (input[currentIndex] == ' ')
            currentIndex++; // начало следующего числа (или конца строки)
        
    }

    // Динамическое выделение памяти под массив целых чисел
    int* numbers = new int[numCount];

    currentIndex = 0;
    size_t index = 0;

    // Считывание чисел в массив целых чисел
    while (input[currentIndex] != '\0') {
        int number = 0;

        while (!isSeparator(input[currentIndex])) {
            number = number * 10 + (input[currentIndex] - '0');
            currentIndex++;
        }
        numbers[index++] = number;
        if (input[currentIndex] == ' ')
            currentIndex++;
    }

    //Cортировка массива целых чисел
    sortArray(numbers, numCount, compareIntegers);


    // Динамическое выделение памяти под C-строку
    // у result будет та же длина как у input
    // [42 7 15 93 2, '\0']
    // [2 7 15 42 93]
    char* result = new char[my_strlen(input)+1];
    result[0] = '\0'; // Пустая строка в начале

    // Запись упорядоченных чисел в C-строку с пробелами
    index = 0;
    for (size_t i = 0; i < numCount; ++i) {
        int number = numbers[i];

        // Конвертация числа в строку
        char temp[11]; // Максимальная длина числа 10 символов + 1 для '\0'
        int length = 0;

        do {
            temp[length++] = '0' + number % 10;
            number /= 10;
        } while (number > 0);

        // Копирование числа в обратном порядке в C-строку
        for (int j = length - 1; j >= 0; --j) {
            result[index++] = temp[j];
        }

        if (i < numCount - 1) {
            result[index++] = ' ';
        }
    }

    // Установка завершающего нуля
    result[index] = '\0';

    // Освобождение выделенной памяти
    delete[] numbers;

    return result;
}


// Получение следующего слова из строки
const char* getNextWord(const char* input, size_t& startIndex) {
    // Пропуск разделителей
    while (isSeparator(input[startIndex]))
        startIndex++;

    size_t endIndex = startIndex;
    // Поиск конца текущего слова
    while (!isSeparator(input[endIndex]))
        endIndex++;

    // Выделение памяти и копирование слова
    size_t wordLength = endIndex - startIndex;
    char* word = new char[wordLength + 1];

    for(size_t i= 0; i<wordLength; i++){
        word[i] = input[startIndex + i];
    }
    // strncpy(word, input + startIndex, wordLength);
    word[wordLength] = '\0';

    // Обновление индекса для следующего слова
    startIndex = endIndex;
    return word;
}


// ЗАДАНИЕ №2
// Поиск слов заданной длины в строке
const char** findWordsByLength(const char* input, int m, size_t& resultCount) {
    size_t startIndex = 0;

    // Подсчет количества слов нужной длины
    while (input[startIndex] != '\0') {
        const char* word = getNextWord(input, startIndex);
        if (my_strlen(word) == m)
            resultCount++;
        delete[] word;
    }

    // Выделение памяти под массив указателей
    const char** result = new const char*[resultCount];
    // Было бы проще использовать вектор
    // И как только мы обнаружим слово по критерию, 
    // мы сразу добавляем его в вектор 

    startIndex = 0;
    size_t currentIndex = 0;
    // Заполнение массива указателей словами нужной длины
    while (currentIndex < resultCount) {
        const char* word = getNextWord(input, startIndex);
        if (my_strlen(word) == m) {
            result[currentIndex++] = word;
        } else {
            delete[] word;
        }
    }
    return result;
}


// ЗАДАНИЕ №3
// Исключение слов с заданным символом
const char* excludeWordsWithChar(const char* input, char excludedChar) {
    // Времмено сюда запишем слова удоств. условию
    char* temp = new char[my_strlen(input)+1];
    
    size_t idx = 0, startIndex = 0, beg; // Индексы в temp и input
    
    // Обработка слов в строке
    while (input[startIndex] != '\0') {
        beg = idx;
        const char* word = getNextWord(input, startIndex);

        bool hasExcludedChar = false;
        size_t word_len = my_strlen(word);

        for (size_t i = 0; i < word_len; i++) {
            temp[idx++] = word[i];
            if (word[i] == excludedChar) {
                hasExcludedChar = true;
                break;
            }
        }

        // Оставляем слово в временном результате, 
        // если не содержит исключенный символ
        // Иначе мы удаляем
        if (!hasExcludedChar) {
            // Если это не последнее слово, добавляем пробел
            if (input[startIndex] != '\0') {
                temp[idx++] = ' ';
            }
        }else{
            // Если содержит исключенный символ, то "удаляем его"
            idx = beg;
        }

        // Освобождение памяти для текущего слова
        delete[] word;
    }
    // Добавляем завершающий нуль
    temp[idx] = '\0';

    // Выделяем память под новую строку с нужной длиной
    char* resultStr = new char[idx+1];

    // Копируем данные из вектора в строку
    for(size_t i=0; i < idx+1; i++){
        resultStr[i] = temp[i];
    }

    delete[] temp;

    return resultStr;
}