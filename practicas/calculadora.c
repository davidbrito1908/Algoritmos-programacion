#include <stdio.h>
//DAVID BRITO 30521360

float suma(float a, float b);
float resta(float a, float b);
float mult(float a, float b);
float division(float a, float b);

void main(){
    int op;
    float x,y;

    //PEDIR OPERACION A REALIZAR
    do{
        printf("Que operacion desea realizar? (1=suma, 2=resta, 3=multiplicacion, 4=division):\n");
        scanf("%i", &op);
    } while(op>4 || op<1);

    //PEDIR OPERANDOS
    printf("Ingrese los dos numeros a operar:\n");
    scanf("%f", &x);
    scanf("%f", &y);

    switch(op){
        case 1: printf("%f", suma(x,y)); break;
        case 2: printf("%f", resta(x,y)); break;
        case 3: printf("%f", mult(x,y)); break;
        case 4: 
        //VERIFICAR QUE SEA UNA DIVISION VALIDA
        if(y==0){
            //DIVISION INVALIDA
            printf("ERROR: No se puede dividir por cero\n");
        }else{
            printf("%f", division(x,y));
        }
        break;
    }
    
}

//FUNCIONES
float suma(float a, float b){
    return (a+b);
}
float resta(float a, float b){
    return (a-b);
}
float mult(float a, float b){
    return (a*b);
}
float division(float a, float b){
    return (a/b);
}
