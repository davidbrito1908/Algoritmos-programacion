/* Realizar un programa en lenguaje c que lea el vector de un maximo de 10 posiciones,
sabiendo que dichos datos son de tipo entero, luego determine el promedio de todos los valores y el mayor de los
valores. asi como tambien que imprima todos los datos. Use funciones. */

#include <stdio.h>
#define n 10

//FUNCIONES
void leer(int vector[n]);
float promedio(int vector[n]);
int mayor(int vector[n]);
void imprimir(int vector[n]);

//Variables globales
int vec[n];
int i, suma=0;
int mayor_pos;
float promedio_pos;

void main(){
    leer(vec);
    promedio(vec);
    mayor(vec);
    imprimir(vec);
}

void leer(int vector[n]){
    for ( i = 0; i < n; ++i){
        printf("Ingrese el #%i\n", i+1);
        scanf("%i",&vector[i]);
    }
}
float promedio(int vector[n]){
    for ( i = 0; i < n; ++i){
        suma+=vector[i];
    }
    promedio_pos=(suma*1.0)/n;
    return (promedio_pos);
}
int mayor(int vector[n]){
    mayor_pos=0;
    for ( i = 0; i < n; ++i){
        if(mayor_pos<vector[i]){
            mayor_pos=vector[i];
        }
    }
    return (mayor_pos);
}

void imprimir(int vector[n]){
    for ( i = 0; i < n; ++i){
        printf("El numero en la posicion %i es: %i\n", i+1, vector[i]);
    }
    printf("El promedio es: %f\n", promedio_pos);
    printf("El mayor de los numeros es: %i\n", mayor_pos);
}