#include <stdio.h>

float main(){
    const float precio1= 3;
    const float precio2= 0.72;
    const float cambio_dolares= 1.06;
    float cant_aux,cant,sobrante, kilos_a,kilos_c;
    int a;
    printf("Ingrese la cantidad de dinero:\n");
    scanf("%f", &cant);
    //Convertir de euros a dolares
    cant=cant*cambio_dolares;

    cant_aux=cant/2;
    kilos_a=cant_aux/precio1;

    cant_aux=cant/3;
    kilos_c=cant_aux/precio2;

    sobrante= cant - (kilos_a*precio1) - (kilos_c*precio2);
    printf("Con %f $ se pudo comprar %f kilos de azucar y %f kilos de cafe, sobraron %f$", cant,kilos_a,kilos_c,sobrante);
    
    //Cerrar el programa
    do{
        printf("\nPresione 1 para cerrar el programa: ");
        scanf("%i",&a);
    } while (a!=1);
}