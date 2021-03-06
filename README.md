# Algoritmos y Estructuras de Datos: Linked List 馃摎

## Enunciado

Un cine ha decidido regalar entradas gratis para una de sus funciones, pero bajo ciertas condiciones. El cine ha formado a las diversas personas que han llegado para las entradas en dos filas del mismo tama帽o **n**. Las condiciones para obtener una entrada son las siguientes:

- Entre las dos personas que est茅n al frente de la fila, la persona que tenga la menor edad se gana una entrada y entra a la funci贸n.

- Si dos personas tienen la misma edad, ambas personas ganan entrada y entran a la funci贸n.

- Si s贸lo queda una fila con personas, estas ir谩n ganando entradas en el orden que se encuentran hasta que se acaben las entradas.

- Puede darse el caso en que sobren entradas.

El cine cuenta con una cantidad limitada de entradas para la funci贸n, por lo tanto, precisa saber el orden en el que quedan las personas en las filas al momento en que se agotan las entradas. Tambi茅n precisa saber el orden en el que han ingresado las personas a la funci贸n.

Para lo anterior, se pide utilizar el lenguaje de programaci贸n **C**, y utilizando listas enlazadas, indicar el orden en el que han ingresado las personas a la funci贸n y el estado de las dos filas al momento en que se han acabado las entradas.

Como entrada para su programa, se ingresar谩 un archivo de texto el cual contendr谩 las dos filas de personas, en donde cada persona ser谩 identificada con su edad. A su vez, por l铆nea de comandos, se pedir谩 ingresar la cantidad de entradas disponibles para dar.

Se pide que como salida se genere un archivo de texto en donde se generan tres columnas, en donde cada columna ser谩:

- La **primera fila** con las personas que no consiguieron entrar a la funci贸n.

- La **segunda fila** con las personas que no consiguieron entrar a la funci贸n.

- Las personas que lograron entrar a la funci贸n en el orden correspondiente.

Para el caso de la representaci贸n de las filas, se considera que el primer elemento de la lista es la primera persona en la fila, y para el caso de las personas que han entrado, el primer elemento de la lista corresponde a la primera persona en haber ingresado a la funci贸n.

## Ejemplo

En la _figura 1_ se puede ver un ejemplo de archivo de entrada, donde la primera columna orresponde a cada persona de la fila 1 con su respectiva edad, y en la columna dos a cada persona de la fila 2 con su respectiva edad.

![Figura 1](figura-1.png)
_Figura 1. Ejemplo archivo de entrada._

En la _figura 2_ se puede observar un ejemplo de archivo de salida dada la entrada presentada en la figura 1.

![Figura 2](figura-2.png)
_Figura 2. Ejemplo archivo de salida._
