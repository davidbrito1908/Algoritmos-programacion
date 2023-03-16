#include <stdio.h>


void main(){
    int num, a;
    printf("Ingrese un numero entero:\n");
    scanf("%i",&num);
    if(num%2==0){
        printf("ES PAR\n");
    }
    else{
        printf("ES IMPAR\n");  
    }

    //Cerrar el programa
    do{
        printf("\nPresione 1 para cerrar el programa: ");
        scanf("%i",&a);
    } while (a!=1);
}