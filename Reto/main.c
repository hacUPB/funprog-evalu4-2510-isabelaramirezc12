#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char* texto = NULL;
    char nombreArchivo[100];
    char nombreSalida[100];
    int opcion;
    int modificado = 0;

    printf("Por favor ingrese el nombre del archivo de entrada (.txt): ");
    scanf("%s", nombreArchivo);

    texto = cargarArchivo(nombreArchivo);
    if (!texto) {
        printf("Errorrrr, no se puede abrir el archivo\n");
        return 1;
    }

    do {
        printf("\nMENÚ\n");
        printf("1. Ver estadísticas del texto\n");
        printf("2. Ver frecuencia de vocales\n");
        printf("3. Buscar y reemplazar palabra\n");
        printf("4. Guardar resultados en archivo\n");
        printf("5. Salir\n");
        printf("Por favor seleccione una opción: ");
        scanf("%d", &opcion);
        getchar();

        switch (opcion) {
            case 1:
                mostrarEstadisticas(texto);
                break;

            case 2:
                contarVocales(texto);
                break;

            case 3:
                texto = reemplazarPalabra(texto);
                modificado = 1;
                break;

            case 4:
                printf("El nombre del archivo de salida es: ");
                scanf("%s", nombreSalida);
                guardarResultados(nombreSalida, texto, modificado);
                printf("Los resultados se guardaron en:  '%s'\n", nombreSalida);
                break;

            case 5:
                printf("Salir\n");
                break;

            default:
                printf("Errorrrrr, Por favor seleccione nuevamente la opción deseada\n");
                break;
        }
    } while (opcion != 5);

    free(texto);
    return 0;
}
