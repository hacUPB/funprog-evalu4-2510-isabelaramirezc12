// Ejercicios propuestos

// 1. Crear una función que reciba un arreglo de enteros y su tamaño, y calcule el promedio de sus valores.

float calcularPromedio(int arr[], int tam) {
    int suma = 0;
    for (int i = 0; i < tam; i++) {
        suma += arr[i];
    }
    return (float)suma / tam;
}

// 2. Escribir una función que reciba un arreglo y lo ordene en orden ascendente usando el método burbuja.

void ordenarBurbuja(int arr[], int tam) {
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 3. Crear una función que reciba un arreglo y devuelva el valor máximo contenido en él.

int valorMaximo(int arr[], int tam) {
    int max = arr[0];
    for (int i = 1; i < tam; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
