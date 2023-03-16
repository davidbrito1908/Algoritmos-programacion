#include <stdio.h>

int main(){
    int a,b,c;
    printf("Ingrese tres numeros enteros:\n");
    scanf("%i", &a);
    scanf("%i", &b);
    scanf("%i", &c);
    if(a>b){
        if(a>c){
            printf("El mayor es %i",a);
        }
        else{
            printf("El mayor es %i",c);
        }
    }
    else{
        if(b>c){
            printf("El mayor es %i",b);
        }
        else{
            printf("El mayor es %i",c);
        }
    }

    //Cerrar el programa
    do{
        printf("\nPresione 1 para cerrar el programa: ");
        scanf("%i",&a);
    } while (a!=1);
}

