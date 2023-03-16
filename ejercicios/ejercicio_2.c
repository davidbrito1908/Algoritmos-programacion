#include <stdio.h>
#include <math.h>

float main(){
    float lado, volumen;
    int a;
    printf("Ingrese el valor de la arista:\n");
    scanf("%f", &lado);
    volumen = pow(lado,3);
    printf("El volumen del cubo es de %fu^3", volumen);


    //Cerrar el programa
    do{
        printf("\nPresione 1 para cerrar el programa: ");
        scanf("%i",&a);
    } while (a!=1);
}