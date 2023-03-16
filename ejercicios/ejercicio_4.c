#include <stdio.h>

void main(){
    int h,m,s,seg,a;
    printf("Ingrese una hora:\n");
    scanf("%i", &h);
    printf("Ingrese el minuto:\n");
    scanf("%i", &m);
    printf("Ingrese los segundos:\n");
    scanf("%i", &s);
    seg=s+(m*60)+(h*3600);
    printf("Han pasado %i segundos desde las 00:00:00",seg);

    //Cerrar el programa
    do{
        printf("\nPresione 1 para cerrar el programa: ");
        scanf("%i",&a);
    } while (a!=1);
}