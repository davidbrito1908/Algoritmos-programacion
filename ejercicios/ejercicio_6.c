#include <stdio.h>

void main(){
    const float conversion=166.386;
    int dolares,a;
    float euros;

    printf("Ingrese una cantidad en dolares: \n");
    scanf("%i",&dolares);
    euros= dolares / conversion;
    
    printf("El equivalente en euros es de: %f", euros);
    //Cerrar el programa
    do{
        printf("\nPresione 1 para cerrar el programa: ");
        scanf("%i",&a);
    } while (a!=1);
}