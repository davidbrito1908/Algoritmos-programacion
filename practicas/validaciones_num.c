#include <stdio.h>
#include <math.h>

void main(){
    int n,num, i,aux, cont=1,con3=0,con5=0,inverso=0,pos;
    do{
        printf("Ingrese la cantidad de numeros a colocar:\n");
        scanf("%i",&n);
    }while(n<1);
    
    for(i=1;i<=n;i++){
        printf("Ingrese un numero:\n");
        scanf("%i",&num);

        aux=num;
        inverso=0;
        cont=1;
        do{
            aux=num%10;
            num=num/10;
            if(aux==3){
                con3++;
            }
            if(aux==5){
                con5++;
            }
            printf("%i\n",aux); 
            /*Crear el numero con orden inverso de digitos*/
            printf("cont= %i\n",cont); 
            inverso=(inverso*10)+aux;
            printf("%i\n",inverso); 
            cont++;
        }while(num!=0);
        if(cont>3){
            printf("Tiene mas de 3 digitos, con cifras invertidas es %i\n",inverso);
        }
    }
    printf("Se introdujeron %i tres y %i cincos",con3,con5);
}