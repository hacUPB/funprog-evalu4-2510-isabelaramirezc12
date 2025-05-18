## Investigación:

### De `<string.h>`:

- `strlen`, `strcpy`, `strncpy`, `strcat`, `strncat`, `strcmp`, `strncmp`, `strchr`, `strstr`, `strtok`

### De `<ctype.h>`:

- `isalpha`, `isdigit`, `isalnum`, `islower`, `isupper`, `tolower`, `toupper`


# Informe: Funciones de `<string.h>` y `<ctype.h>` en C

---

## Funciones de `<string.h>`

### 1. `strlen`
- **Prototipo**: `size_t strlen(const char *str);`
- **Uso**: Calcula la longitud de una cadena sin contar el `'\0'`.
- **Parámetro**: `str` es la cadena de caracteres.
```c
#include <stdio.h>
#include <string.h>
int main() {
    char texto[] = "Hola";
    printf("Longitud: %lu\n", strlen(texto));
    return 0;
}
```

### 2. `strcpy`
- **Prototipo**: `char *strcpy(char *dest, const char *src);`
- **Uso**: Copia `src` en `dest`, incluyendo el terminador nulo.
```c
#include <stdio.h>
#include <string.h>
int main() {
    char destino[20];
    strcpy(destino, "Copia esto");
    printf("%s\n", destino);
    return 0;
}
```

### 3. `strncpy`
- **Prototipo**: `char *strncpy(char *dest, const char *src, size_t n);`
- **Uso**: Copia hasta `n` caracteres.
```c
#include <stdio.h>
#include <string.h>
int main() {
    char destino[10];
    strncpy(destino, "Ejemplo", 4);
    destino[4] = '\0';
    printf("%s\n", destino);
    return 0;
}
```

### 4. `strcat`
- **Prototipo**: `char *strcat(char *dest, const char *src);`
- **Uso**: Concatena `src` al final de `dest`.
```c
#include <stdio.h>
#include <string.h>
int main() {
    char a[20] = "Hola ";
    strcat(a, "mundo");
    printf("%s\n", a);
    return 0;
}
```

### 5. `strncat`
- **Prototipo**: `char *strncat(char *dest, const char *src, size_t n);`
- **Uso**: Concatena hasta `n` caracteres.
```c
#include <stdio.h>
#include <string.h>
int main() {
    char a[20] = "Hola ";
    strncat(a, "universo", 4);
    printf("%s\n", a);
    return 0;
}
```

### 6. `strcmp`
- **Prototipo**: `int strcmp(const char *s1, const char *s2);`
- **Uso**: Compara dos cadenas.
```c
#include <stdio.h>
#include <string.h>
int main() {
    int r = strcmp("hola", "hola");
    printf("%d\n", r); // 0 si son iguales
    return 0;
}
```

### 7. `strncmp`
- **Prototipo**: `int strncmp(const char *s1, const char *s2, size_t n);`
- **Uso**: Compara hasta `n` caracteres.
```c
#include <stdio.h>
#include <string.h>
int main() {
    int r = strncmp("hola", "holanda", 4);
    printf("%d\n", r); // 0 si coinciden los primeros 4 caracteres
    return 0;
}
```

### 8. `strchr`
- **Prototipo**: `char *strchr(const char *str, int c);`
- **Uso**: Busca la primera aparición de `c`.
```c
#include <stdio.h>
#include <string.h>
int main() {
    char *p = strchr("programa", 'g');
    if (p) printf("Encontrado: %s\n", p);
    return 0;
}
```

### 9. `strstr`
- **Prototipo**: `char *strstr(const char *haystack, const char *needle);`
- **Uso**: Busca la primera subcadena `needle`.
```c
#include <stdio.h>
#include <string.h>
int main() {
    char *p = strstr("Hola mundo", "mun");
    if (p) printf("Subcadena encontrada: %s\n", p);
    return 0;
}
```

### 10. `strtok`
- **Prototipo**: `char *strtok(char *str, const char *delim);`
- **Uso**: Divide una cadena en tokens usando delimitadores.
```c
#include <stdio.h>
#include <string.h>
int main() {
    char texto[] = "uno,dos,tres";
    char *tok = strtok(texto, ",");
    while (tok) {
        printf("%s\n", tok);
        tok = strtok(NULL, ",");
    }
    return 0;
}
```

---

## Funciones de `<ctype.h>`

### 1. `isalpha`
- **Prototipo**: `int isalpha(int c);`
- **Uso**: Verifica si el carácter es alfabético.
```c
#include <stdio.h>
#include <ctype.h>
int main() {
    if (isalpha('A')) printf("Es letra\n");
    return 0;
}
```

### 2. `isdigit`
- **Prototipo**: `int isdigit(int c);`
- **Uso**: Verifica si el carácter es un dígito.
```c
#include <stdio.h>
#include <ctype.h>
int main() {
    if (isdigit('5')) printf("Es dígito\n");
    return 0;
}
```

### 3. `isalnum`
- **Prototipo**: `int isalnum(int c);`
- **Uso**: Verifica si es letra o dígito.
```c
#include <stdio.h>
#include <ctype.h>
int main() {
    if (isalnum('9')) printf("Es letra o dígito\n");
    return 0;
}
```

### 4. `islower`
- **Prototipo**: `int islower(int c);`
- **Uso**: Verifica si es letra minúscula.
```c
#include <stdio.h>
#include <ctype.h>
int main() {
    if (islower('m')) printf("Es minúscula\n");
    return 0;
}
```

### 5. `isupper`
- **Prototipo**: `int isupper(int c);`
- **Uso**: Verifica si es letra mayúscula.
```c
#include <stdio.h>
#include <ctype.h>
int main() {
    if (isupper('Z')) printf("Es mayúscula\n");
    return 0;
}
```

### 6. `tolower`
- **Prototipo**: `int tolower(int c);`
- **Uso**: Convierte a minúscula.
```c
#include <stdio.h>
#include <ctype.h>
int main() {
    char c = tolower('T');
    printf("%c\n", c);
    return 0;
}
```

### 7. `toupper`
- **Prototipo**: `int toupper(int c);`
- **Uso**: Convierte a mayúscula.
```c
#include <stdio.h>
#include <ctype.h>
int main() {
    char c = toupper('r');
    printf("%c\n", c);
    return 0;
}
```

## Preguntas de control

Aquí tienes las respuestas concisas y claras a las preguntas de control:


1. **¿Por qué `sizeof("Hola")` devuelve 5, pero `strlen("Hola")` devuelve 4?**

- Respuesta: Porque `sizeof` cuenta todos los caracteres incluyendo el `'\0'` al final, mientras que `strlen` no lo hace (solo cuenta los visibles).

2. **¿Cuál es la diferencia práctica entre declarar una cadena como arreglo (`char saludo[]`) y como puntero (`char *saludo`)?**

- Respuesta: El arreglo reserva espacio en la pila y permite modificar el contenido, mientras que el puntero puede apuntar a cualquier ubicación, incluso a cadenas constantes que no se deben modificar.

3. **¿Cómo evitas un "buffer overflow" al copiar o concatenar cadenas?**

- Respuesta: Usando funciones seguras como `strncpy` o `strncat`, para controlar el tamaño del búfer y asegurar que haya suficiente espacio para el terminador nulo.

4. **¿Qué hace exactamente la función `strcspn()` y por qué es útil usarla junto con `fgets()`?**

-Respuesta: `strcspn()` devuelve la posición del primer carácter que coincide con otro de una cadena dada y se usa con `fgets()` para eliminar el salto de línea (`'\n'`) al final de la entrada.

5. **¿Qué pasos debes seguir para manejar correctamente una cadena reservada dinámicamente con `malloc()`?**

- Respuesta: Reservar memoria suficiente, verificar que `malloc` no devuelva `NULL`, usar la cadena con seguridad y liberar la memoria con `free()` cuando ya no se necesite.

