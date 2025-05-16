##include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* cargarArchivo(const char* nombreArchivo);
void mostrarEstadisticas(const char* texto);
void contarVocales(const char* texto);
char* reemplazarPalabra(char* texto);
void guardarResultados(const char* nombreArchivo, const char* texto, int incluirTexto);

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
        printf("Lo siento, hay un error al abrir el archivo.\n");
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
                printf("Los resultados han sido guardados en '%s'\n", nombreSalida);
                break;

            case 5:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Error: esa opción no está disponible. Por favor, seleccione otra.\n");
                break;
        }
    } while (opcion != 5);

    free(texto);
    return 0;
}

// ------------------- FUNCIONES -------------------

char* cargarArchivo(const char* nombreArchivo) {
    FILE* file = fopen(nombreArchivo, "r");
    if (!file) return NULL;

    fseek(file, 0, SEEK_END);
    long tam = ftell(file);
    rewind(file);

    char* buffer = malloc((tam + 1) * sizeof(char));
    if (!buffer) return NULL;

    fread(buffer, sizeof(char), tam, file);
    buffer[tam] = '\0';

    fclose(file);
    return buffer;
}

void mostrarEstadisticas(const char* texto) {
    int caracteres = 0, palabras = 0, espacios = 0, lineas = 0;
    int enPalabra = 0;

    for (int i = 0; texto[i] != '\0'; i++) {
        char c = texto[i];
        if (c != '\n') caracteres++;
        if (c == ' ') espacios++;
        if (c == '\n') lineas++;

        if (!isspace(c) && !enPalabra) {
            palabras++;
            enPalabra = 1;
        } else if (isspace(c)) {
            enPalabra = 0;
        }
    }

    printf("\n--- Estadísticas del texto ---\n");
    printf("Caracteres (sin \\n): %d\n", caracteres);
    printf("Palabras: %d\n", palabras);
    printf("Espacios en blanco: %d\n", espacios);
    printf("Líneas: %d\n", lineas + 1);
}

void contarVocales(const char* texto) {
    int conteo[5] = {0};

    for (int i = 0; texto[i] != '\0'; i++) {
        char c = tolower(texto[i]);
        if (c == 'a') conteo[0]++;
        else if (c == 'e') conteo[1]++;
        else if (c == 'i') conteo[2]++;
        else if (c == 'o') conteo[3]++;
        else if (c == 'u') conteo[4]++;
    }

    printf("\n--- Frecuencia de vocales ---\n");
    printf("a: %d\n", conteo[0]);
    printf("e: %d\n", conteo[1]);
    printf("i: %d\n", conteo[2]);
    printf("o: %d\n", conteo[3]);
    printf("u: %d\n", conteo[4]);
}

char* reemplazarPalabra(char* texto) {
    char buscar[50], reemplazo[50];
    printf("Palabra que se desea buscar: ");
    scanf("%s", buscar);
    printf("Palabra que se desea reemplazar: ");
    scanf("%s", reemplazo);

    char* nuevoTexto = NULL;
    int nuevoTam = 0;
    int tamBuscar = strlen(buscar);
    int tamReemplazo = strlen(reemplazo);

    char* temp = texto;
    while ((temp = strstr(temp, buscar)) != NULL) {
        nuevoTam += tamReemplazo;
        temp += tamBuscar;
    }

    nuevoTam += strlen(texto) + 1;
    nuevoTexto = malloc(nuevoTam);

    if (!nuevoTexto) return texto;

    char* pos = texto;
    char* escribir = nuevoTexto;

    while (*pos) {
        if (strstr(pos, buscar) == pos) {
            strcpy(escribir, reemplazo);
            escribir += tamReemplazo;
            pos += tamBuscar;
        } else {
            *escribir++ = *pos++;
        }
    }
    *escribir = '\0';

    free(texto);
    return nuevoTexto;
}

void guardarResultados(const char* nombreArchivo, const char* texto, int incluirTexto) {
    FILE* salida = fopen(nombreArchivo, "w");
    if (!salida) {
        printf("Error: no se puede abrir el archivo de salida\n");
        return;
    }

    fprintf(salida, "\n--- Estadísticas del texto ---\n");

    int caracteres = 0, palabras = 0, espacios = 0, lineas = 0, enPalabra = 0;
    for (int i = 0; texto[i] != '\0'; i++) {
        char c = texto[i];
        if (c != '\n') caracteres++;
        if (c == ' ') espacios++;
        if (c == '\n') lineas++;
        if (!isspace(c) && !enPalabra) {
            palabras++;
            enPalabra = 1;
        } else if (isspace(c)) {
            enPalabra = 0;
        }
    }

    fprintf(salida, "Caracteres (sin \\n): %d\n", caracteres);
    fprintf(salida, "Palabras: %d\n", palabras);
    fprintf(salida, "Espacios en blanco: %d\n", espacios);
    fprintf(salida, "Líneas: %d\n", lineas + 1);

    fprintf(salida, "\n--- Frecuencia de vocales ---\n");
    int conteo[5] = {0};
    for (int i = 0; texto[i] != '\0'; i++) {
        char c = tolower(texto[i]);
        if (c == 'a') conteo[0]++;
        else if (c == 'e') conteo[1]++;
        else if (c == 'i') conteo[2]++;
        else if (c == 'o') conteo[3]++;
        else if (c == 'u') conteo[4]++;
    }

    fprintf(salida, "a: %d\n", conteo[0]);
    fprintf(salida, "e: %d\n", conteo[1]);
    fprintf(salida, "i: %d\n", conteo[2]);
    fprintf(salida, "o: %d\n", conteo[3]);
    fprintf(salida, "u: %d\n", conteo[4]);

    if (incluirTexto) {
        fprintf(salida, "\n--- Texto modificado ---\n");
        fprintf(salida, "%s\n", texto);
    }

    fclose(salida);
}
