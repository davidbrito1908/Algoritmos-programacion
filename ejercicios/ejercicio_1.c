#include <stdio.h>

float main(){
    float n1,n2,n3, promedio;
    int a;
    printf("Ingrese la primera nota:\n");
    scanf("%f", &n1);
    printf("Ingrese la segunda nota:\n");
    scanf("%f", &n2);
    printf("Ingrese la tercera nota:\n");
    scanf("%f", &n3);
    promedio = (n1+n2+n3)/3;
    printf("El promedio final es de %f", promedio);
    
    //Cerrar el programa
    do{
        printf("\nPresione 1 para cerrar el programa: ");
        scanf("%i",&a);
    } while (a!=1);
}