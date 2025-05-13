#include <studio.h>


int main (){
    char* texto = NULL;
    char nombreArchivo [100];
    Char nombreSalida [100];
    int opcion;


printf("Ingrese el nombre del archivo de entrada (.txt): ");
    scanf("%s", nombreArchivo);

    texto = cargarArchivo(nombreArchivo);
    if (!texto) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    do {
        printf("\n--- MENÚ DE ANÁLISIS ---\n");
        printf("1. Ver estadísticas del texto\n");
        printf("2. Ver frecuencia de vocales\n");
        printf("3. Buscar y reemplazar palabra\n");
        printf("4. Guardar resultados en archivo\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

    }
}