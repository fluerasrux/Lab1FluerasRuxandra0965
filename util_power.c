#include <stdio.h>

void util_power(int base, int power)
{
    int result = 1;

    for (int i = 0; i < power; i++) {
        result *= base;
    }
    printf("Inside util_power(): %d^%d = %d\n", base, power, result);
}