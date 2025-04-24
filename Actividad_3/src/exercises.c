// Primer ejercicio

#include "exercises.h"

int sum(int arr[], int size) {
    int suma = 0;
    for (int i = 0; i < size; i++) {
        suma = suma + arr[i];
    }
    return suma;
}
