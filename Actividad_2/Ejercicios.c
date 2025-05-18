// Punto 1

#include <stdio.h>

int main() {

    int numeros[5] = {10, 20, 30, 40, 50};

    printf("El contenido del arreglo y sus direcciones de memoria es: \n");

    for (int i = 0; i < 5; i++) {
        printf("numeros[%d] = %d\t Dirección: %p\n", i, numeros[i], (void*)&numeros[i]);
    }

    return 0;
}

// Punto 2 (preguntas)

// 1. ¿Qué valor contiene el siguiente dato: dato[5], si el arreglo se inicializa de la siguiente manera: int datos[6] = {5, 82, 41};? 
// Respuesta: El valor de datos[5] es 0.


// 2. ¿Cómo determinar el número de elementos en un arreglo cuando su tamaño no se especifica explícitamente?
// Respuesta: Utilizando "SIZEOF"


// Punto 3 (Ejercicios)

// Ejercicio 1

#include <stdio.h>

int main() {
    int numeros[10];

    for (int i = 0; i < 10; i++) {
        numeros[i] = 11 + i;
    }

    printf("Estos son los números en orden descendente:\n");
    for (int i = 9; i >= 0; i--) {
        printf("%d ", numeros[i]);
    }

    printf("\n\n");
    return 0;
}

// Ejercicio 2

#include <stdio.h>

int main() {
    int pares[5] = {2, 4, 6, 8, 10};

    printf("Estos son los números pares en orden ascendente:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", pares[i]);
    }

    printf("\n\n");
    return 0;
}

// Ejercicio 3

#include <stdio.h>

int main() {
    int numeros[10];
    int suma = 0;
    int resta = 0;
    int multiplicacion = 1;

    printf(" Por favor ingrese 10 números enteros:\n");

    for (int i = 0; i < 10; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &numeros[i]);
        suma += numeros[i];
        if (i == 0) {
            resta = numeros[i]; 
        } else {
            resta -= numeros[i];
        }
        multiplicacion *= numeros[i];
    }

    printf("\nLa suma es: %d\n", suma);
    printf("La resta acumulada es: %d\n", resta);
    printf("La multiplicación acumulada es: %d\n\n", multiplicacion);

    return 0;
}


// Ejercicio  4

#include <stdio.h>

int main() {
    int array1[5], array2[5], combinado[10];

    printf("Por favor ingrese 10 números (los primeros 5 para el primer arreglo, los siguientes 5 para el segundo):\n");

    for (int i = 0; i < 5; i++) {
        printf("Primer grupo - Número %d: ", i + 1);
        scanf("%d", &array1[i]);
    }

    for (int i = 0; i < 5; i++) {
        printf("Segundo grupo - Número %d: ", i + 6);
        scanf("%d", &array2[i]);
    }

    // Combinar los dos arreglos 
    for (int i = 0; i < 5; i++) {
        combinado[i] = array1[i];
        combinado[i + 5] = array2[i];
    }

    // Imprimir el arreglo combinado
    printf("\nEste es el arreglo combinado:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", combinado[i]);
    }

    printf("\n");
    return 0;
    
}

// Ejercicio 5

#include <stdio.h>
void analizarNotas(float notas[], int tam)

// main

int main() {
    float notas[24];

    printf("Ingrese por favor las notas de los 24 estudiantes:\n");
    for (int i = 0; i < 24; i++) {
        printf("Nota del estudiante %d: ", i + 1);
        scanf("%f", &notas[i]);
    }

    analizarNotas(notas, 24);

    return 0;
}

// Función del ejercicio 

void analizarNotas(float notas[], int tam) {
    float suma = 0;
    int aprobados = 0;
    int reprobados = 0;
    int sobresalientes = 0;

    for (int i = 0; i < tam; i++) {
        suma += notas[i];

        if (notas[i] >= 3.0) {
            aprobados++;
        } else {
            reprobados++;
        }

        if (notas[i] >= 4.0) {
            sobresalientes++;
        }
    }

    float promedio = suma / tam;

    printf("\n--- Estadísticas del curso ---\n");
    printf("El promedio general es: %.2f\n", promedio);
    printf("Los estudiantes aprobados son: %d\n", aprobados);
    printf("Los estudiantes reprobados son: %d\n", reprobados);
    printf("Los estudiantes con nota >= 4.0 son: %d\n", sobresalientes);
}

// Ejercicio 6

#include <stdio.h>

#define ESTUDIANTES 3
#define ACTIVIDADES 3

int main() {
    float notas[ESTUDIANTES + 1][ACTIVIDADES + 1]; // +1 para el encabezado y la nota definitiva

    printf("Por favor ingrese los porcentajes de las %d actividades:\n", ACTIVIDADES);
    for (int j = 0; j < ACTIVIDADES; j++) {
        printf("El porcentaje de la actividad %d es: ", j + 1);
        scanf("%f", &notas[0][j]);  // Fila 0 es la que almacena los porcentajes
    }


    for (int i = 1; i <= ESTUDIANTES; i++) {
        printf("\nIngrese por favor las notas del estudiante %d:\n", i);
        for (int j = 0; j < ACTIVIDADES; j++) {
            printf("Nota actividad %d: ", j + 1);
            scanf("%f", &notas[i][j]);
        }
    }

    for (int i = 1; i <= ESTUDIANTES; i++) {
        float definitiva = 0;
        for (int j = 0; j < ACTIVIDADES; j++) {
            definitiva += notas[i][j] * notas[0][j];  // Nota * porcentaje
        }
        notas[i][ACTIVIDADES] = definitiva;  // Guardar en la última columna
    }

    // Mostrar resultados
    printf("\n--- Nota definitiva de los estudiantes ---\n");
    for (int i = 1; i <= ESTUDIANTES; i++) {
        printf("Estudiante %d - Nota definitiva: %.2f\n", i, notas[i][ACTIVIDADES]);
    }

    return 0;
}
