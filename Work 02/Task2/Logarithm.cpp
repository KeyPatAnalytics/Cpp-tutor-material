/*#include "pch.h"
#include "Logarithm.h"

int find_log2(int x) { 
    if (x <= 0) return -2;//��� � ������ ���� ���������� ����� ��������
    if (x == 1) return 0;//� = 1 ����� ������ ����� ����� � ������� 0

    int exponent = 0;
    int tchatnoe = x;

    while (tchatnoe != 1) {
        if (tchatnoe % 2 == 1) return -1;
        tchatnoe /= 2; 
        exponent++; 
    }

    return exponent;
}*/
#include "pch.h"
#include "Logarithm.h"
int find_log2(int x)
{
    if (x <= 0) return -2;
    if (x == 1) return 0;

    int exponent = 0;
    int tchasnoe = x;

    while (tchasnoe != 1) {
        if (tchasnoe % 2 == 1) return -1;
        tchasnoe /= 2;
        exponent++;
    }
    return exponent;
}
