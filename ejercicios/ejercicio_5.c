#include <stdio.h>

void main(){
    int v1,v2,aux,a;
    printf("Ingrese el valor de v1: \n");
    scanf("%i",&v1);
    printf("Ingrese el valor de v2: \n");
    scanf("%i",&v2);
    aux=v1;
    v1=v2;
    v2=aux;
    printf("El nuevo valor de v1 es %i y el nuevo valor de v2 es %i",v1,v2);

    //Cerrar el programa
    do{
        printf("\nPresione 1 para cerrar el programa: ");
        scanf("%i",&a);
    } while (a!=1);
}