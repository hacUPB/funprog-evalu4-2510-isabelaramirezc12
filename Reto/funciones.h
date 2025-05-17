# ifndef FUNCIONES_H
#define FUNCIONES_H

char* cargarArchivo(const char* nombreArchivo);
void mostrarEstadisticas(const char* texto);
void contarVocales(const char* texto);
char* reemplazarPalabra(char* texto);
void guardarResultados(const char* nombreArchivo, const char* texto, int incluirTexto);

#endif