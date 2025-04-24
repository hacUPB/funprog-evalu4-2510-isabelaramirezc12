// Ejercicio 1

#include <stdio.h>
#include "exercises.h"

int main() {
    int numeros[] = {12, 6, 7, 21, 9, 1, 10, 26};
    int total = calcSum(numeros, 8);
    printf("La suma es: %d\n", total);
    return 0;
}