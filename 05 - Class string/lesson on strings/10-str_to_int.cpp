#include <iostream>
#include <cstdlib>

int main() {
    const char str[] = "123";
    int num = atoi(str);

    std::cout << "String as number: " << num << std::endl;

    return 0;
}
