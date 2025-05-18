
## Preguntas de comprensión

## ¿Qué se pasa realmente a la función cuando enviamos un arreglo como parámetro?

- Respuesta: Cuando se pasa un arreglo como parámetro a una función, lo que realmente se pasa es la dirección del primer elemento del arreglo, es decir, un puntero.

## ¿Qué diferencia hay entre declarar el parámetro como int arr[] y int *arr?

- Respuesta: Aunque ambos cumplen la misma función la diferencia está en que:

 -int arr[] se usa para aclarar que se usa un arreglo.

 -int *arr se usa cuando se quiere enfatizar que se emplea especificamente una dirección de memoria.


## ¿Qué implicaciones tiene esto sobre la modificación del arreglo dentro de la función?

- Respuesta: Como se pasa una referencia (puntero) al arreglo, cualquier cambio que hase ejecute dentro de la función va a afectar al arreglo original.


## Preguntas finales para reforzar el aprendizaje

## ¿Cuál es exactamente la diferencia entre un arreglo y un puntero?

- Respuesta: Un arreglo es una colección de elementos almacenados en memoria contigua con tamaño fijo, mientras que un puntero es una variable que almacena la dirección de memoria de otro dato.

## ¿Cómo están almacenados en la memoria los elementos de una matriz?

- Respuesta: Los elementos de una matriz se almacenan en memoria de forma lineal y en orden por filas.

## ¿Qué precauciones se deben tomar al usar punteros para recorrer arreglos?

- Respuesta: Es importante tener en cuenta:

-No acceder fuera de los límites del arreglo

-Asegurarse de que el puntero esté bien inicializado

