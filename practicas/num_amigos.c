#include <stdio.h>

void main(){
    int num1,num2, i, acum1=1,acum2=1;
    printf("Ingrese el primer numero:\n");
    scanf("%i",&num1);
    printf("Ingrese el segundo numero:\n");
    scanf("%i",&num2);
    
    for(i=2;i<((num1/2)+1);i++){
        if(num1%i==0){
            /*sumar divisores*/
            printf("%i es divisor de %i \n", i,num1);
            acum1=acum1+i;
        }
    }

    for(i=2;i<((num2/2)+1);i++){
        if(num2%i==0){
            /*sumar divisores*/
            acum2=acum2+i;
            printf("%i es divisor de %i \n", i,num2);
        }
    }

    printf("%i y %i \n", acum1,acum2);

    if((acum1==num2) && (acum2==num1)){
        printf("%i y %i son amigos\n", num1,num2);
    }else{
        printf("%i y %i no son amigos\n", num1,num2);
    }

}