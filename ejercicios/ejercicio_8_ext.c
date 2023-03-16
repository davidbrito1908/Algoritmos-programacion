#include <stdio.h>

int main(){
    int a,b,c;
    printf("Ingrese tres numeros enteros:\n");
    scanf("%i", &a);
    scanf("%i", &b);
    scanf("%i", &c);
    //EXTENDIDO INCLUYENDO TODAS LAS POSIBILIDADES SIN SIMPLIFICAR
    if(a>b){
        if(a>c){
            //a es mayor
            printf("El mayor es %i",a);
        }
        else if(a==c){
            //a y c son mayores
            printf("El mayor es %i",a);
        }
        else{
            //c es mayor
            printf("El mayor es %i",c);
        }
    }
    else if(a==b){
        if(a>c){
            //a y b son mayores
            printf("El mayor es %i",a);
        }
        else{
            //c es mayor
            printf("El mayor es %i",c);
        }
    }
    else{
        if(b>c){
            //b es mayor
            printf("El mayor es %i",b);
        }
        else if(b==c){
            //b y c son mayores
            printf("El mayor es %i",b);
        }
        else{
            //c
            printf("El mayor es %i",c);
        }
    }

    //Cerrar el programa
    do{
        printf("\nPresione 1 para cerrar el programa: ");
        scanf("%i",&a);
    } while (a!=1);
}

