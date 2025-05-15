#include <studio.h>


int main (){
    char* texto = NULL;
    char nombreArchivo [100];
    Char nombreSalida [100];
    int opcion;


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

    }
}

do { ();
switch (opcion){
switch 

case 1:

break;

case 2:

break;

case 3:

break;

case 4:

break;

case 5:
    printf("4. Volver al menú principal\n");
break;

default:
    printf("Errorr, esa opción no está disponible, seleccione otra nuevamente \n");
break;

}

} while(parametro !=5); 

return 0;


// Funciones

char*cargarArchivo(const char* nombreArchivo){


}
