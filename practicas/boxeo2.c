#include <stdio.h>
//PROGRAMA REALIZADO POR DAVID BRITO - C.I: 30521360

struct round{
    int ganador;
    int rounds_azul;
    int rounds_roja;
    int caida_azul;
    int caida_roja;
};


//ACCIONES NOMINADAS
void leer(struct round r[12]);
void asignar_puntuaciones(int juez[3][2][12], int arbitro, struct round r[12]);
void puntuacion_mayor(int *p_mayor,int *mayor, int total_punt[3][2]);
void puntuacion_menor(int *p_menor,int *menor, int total_punt[3][2]);
void resultados_juez(int total_r,int total_a, int *roja, int *azul, int *empate);
void calcular_totales(int juez[3][2][12], int total_puntaje[3][2]);
int tipo_victoria(int g_roja,int g_azul, int empate,int *ganador);
int acumular_puntajes(int k, int total_puntaje[3][2]);
void determinar_aumento(int tipo, float *porc_aum);
void resultados_combate(int ganador, float ganancias[2],int tipov, int rounds_totales[2], int punt1, int punt2);


const int b_inicial=100000; //BOLSA INICIAL

void main(){

    int i,j, tipo_v,
    roja=0,azul=0,empate=0,ganador,puntaje1=0,puntaje2=0,p_mayor=0,p_menor=120,mayor,menor,
    trounds_roja, trounds_azul;
    float ganancias[2];
    int juez[3][2][12];
    int total_puntaje[3][2];
    int rounds_totales[2]={0,0};
    struct round info_round[12];

    for(i=0;i<3;i++){
        printf("---Puntuacion del Juez %i: ---\n",i+1);
        //REINICIAR ROUNDS
        trounds_roja=0;
        trounds_azul=0;
        //LEER INFORMACION DEL JUEZ
        leer(info_round);
        asignar_puntuaciones(juez,i,info_round);

        //ACUMULAR ROUNDS GANADOR POR JUEZ
        for(j=0;j<12;j++){
            trounds_azul+=info_round[j].rounds_azul;
            trounds_roja+=info_round[j].rounds_roja;
        }
        //ACUMULAR ROUNDS GANADOS POR BOXEADOR
        rounds_totales[0]+=trounds_roja;
        rounds_totales[1]+=trounds_azul;

        //PUNTAJES_TOTALES POR JUEZ
        calcular_totales(juez, total_puntaje);
        //ROUND GANADOS Y PUNTOS SEGUN JUEZ i
        printf("El peleador de la esquina roja gano %i rounds y perdio %i, el peleador azul gano %i rounds y perdio %i\n", trounds_roja,12-trounds_roja,trounds_azul,12-trounds_azul);
        printf("El peleador de la esquina roja sumo %i puntos y el peleador azul sumo %i puntos\n", total_puntaje[i][0], total_puntaje[i][1]);
    }

    //CALCULAR RESULTADOS POR JUEZ
    for(i=0;i<3;i++){
        resultados_juez(total_puntaje[i][0],total_puntaje[i][1],&roja,&azul,&empate);
    }

    //PUNTAJE TOTAL POR BOXEADOR 
    puntaje1=acumular_puntajes(0,total_puntaje);          
    puntaje2=acumular_puntajes(1,total_puntaje); 

    //TARJETA CON PUNTUACION MAYOR Y MENOR         
    puntuacion_mayor(&p_mayor,&mayor,total_puntaje);
    puntuacion_menor(&p_menor,&menor,total_puntaje);

    //DETERMINAR GANADOR Y TIPO DE VICTORIA
    tipo_v = tipo_victoria(roja,azul,empate, &ganador);
    //IMPRIMIR RESULTADOS Y CALCULAR GANANCIAS
    resultados_combate(ganador,ganancias,tipo_v, rounds_totales,puntaje1,puntaje2);
    //TARJETA CON MAYOR Y MENOR PUNTUACION
    printf("La tarjeta con mayor puntuacion fue la del juez %i, que otorgo %i a uno de los peleadores\n", mayor, p_mayor);
    printf("La tarjeta con menor puntuacion fue la del juez %i, que otorgo %i a uno de los peleadores\n", menor, p_menor);
    //GANANCIA BOXEADORES
    printf("El boxeador de la esquina roja ganara %.2f dolares y el de la esquina azul ganara %.2f dolares", ganancias[0],ganancias[1]);
}


void leer(struct round r[12]){
    int tr,g,ta,cr,ca,j;
    for(j=0;j<12;j++){
        tr=0;
        ta=0;
        printf("ROUND %i\n", j+1);
        do{
            printf("Ingrese el ganador del round (1=Esquina roja, 2=Esquina azul)\n");
            scanf("%i", &g);
        } while(g!=1 && g!=2);
        if(g==1){
            tr=1;
        }else{
            ta=1;
        }

        do{
            printf("Cayo a la lona el peleador de la esquina roja? (1=Si, 2=No)\n");
            scanf("%i", &cr);
        } while(cr!=1 && cr!=2);            
        do{
            printf("Cayo a la lona el peleador de la esquina azul? (1=Si, 2=No)\n");
            scanf("%i", &ca);
        } while(ca!=1 && ca!=2);

        r[j].ganador=g;
        r[j].rounds_azul=ta;
        r[j].rounds_roja=tr;
        r[j].caida_azul=ca;
        r[j].caida_roja=cr;
    }
}


void asignar_puntuaciones(int juez[3][2][12], int arbitro, struct round r[12]){
    // int caida_r,caida_a;
    int trojas, tazules, round;
    for(round=0;round<12;round++){
        if(r[round].ganador==1){
                    trojas=10;
                    tazules=9;   
            } 
            else{
                tazules=10;
                trojas=9;
        }
        if(r[round].caida_roja==1){
            trojas=trojas-2;
        }
        if(r[round].caida_azul==1){
            tazules=tazules-2;
        }
        juez[arbitro][0][round]=trojas;
        juez[arbitro][1][round]=tazules;
        printf("PUNTAJE DEL ROUND %i: %i esquina roja y %i esquina azul\n\n",round+1, juez[arbitro][0][round],juez[arbitro][1][round]);
    }
}

void puntuacion_mayor(int *p_mayor,int *mayor, int total_punt[3][2]){
    int i,j;

    for(i=0;i<3;i++){
        for(j=0;j<2;j++){
            if(total_punt[i][j]>*p_mayor){
                *mayor=i+1;
                *p_mayor=total_punt[i][j];
            }
        }
    }
}
void puntuacion_menor(int *p_menor,int *menor, int total_punt[3][2]){
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<2;j++){
            if(total_punt[i][j]<*p_menor){
                *menor=i+1;
                *p_menor=total_punt[i][j];
            }
        }
    }
}
void resultados_juez(int total_r,int total_a, int *roja, int *azul, int *empate){
    //CONTAR RESULTADO DE CADA JUEZ
    int r,e,a;
    r=*roja;
    e=*empate;
    a=*azul;
    if(total_r>total_a){
        r+=1;
        *roja=r;
    }else{
        if(total_r==total_a){
            e+=1;
            *empate=e;

        } else{
            a+=1;
            *azul=a;
        }
    }
}

int acumular_puntajes(int k, int total_puntaje[3][2]){
    int i,puntaje=0;
    for(i=0;i<3;i++){
        puntaje+=total_puntaje[i][k];
    }
    return puntaje;
} 

void calcular_totales(int juez[3][2][12], int total_puntaje[3][2]){
    int i,j,total_azul,total_roja;
    for(i=0;i<3;i++){
        total_azul=0;
        total_roja=0;
    
        for(j=0;j<12;j++){
            total_roja+=juez[i][0][j]; // puntaje total de la equina roja
            total_azul+=juez[i][1][j]; // puntaje total de la equina azul
        }
        total_puntaje[i][0]=total_roja;
        total_puntaje[i][1]=total_azul;
       
     }
}

int tipo_victoria(int g_roja,int g_azul, int empate,int *ganador){
    int victoria;
    if(g_roja>1){
        *ganador=1;
        if(g_azul==1){
            //DIVIDIDA=1
            victoria=1;
        }
        if(g_roja==3){
            //UNANIME=2
            victoria=2;
        }
        if(empate==1){
            //POR MAYORIA=3
            victoria=3;
        }
    }else{
        //GANADOR ESQUINA AZUL
        if(g_azul>1){
            *ganador=2;
            if(g_roja==1){
                //DIVIDIDA=1
                victoria=1;
            }
            if(g_azul==3){
                //UNANIME=2
                victoria=2;
            }
            if(empate==1){
                //POR MAYORIA=3
                victoria=3;
            }

        }else{
            *ganador=0;
            victoria=-1; //EMPATE
        }
    }
    return victoria;
}

void determinar_aumento(int tipo, float *porc_aum){
    switch(tipo){
        case 1:
            printf("Por decision dividida:\n");
            *porc_aum=0.05;
            break;
        case 2:
            printf("Por decision unanime:\n");
            *porc_aum=0.10;  
            break;
        case 3:
            printf("Por decision por mayoria:\n");
            *porc_aum=0.15;  
            break;
    }
}
void resultados_combate(int ganador, float ganancias[2],int tipov, int rounds_totales[2], int punt1, int punt2){
    float porc_aum;
    //DETERMINAR PORCENTAJE DE AUMENTO SEGUN TIPO DE VICTORIA
    determinar_aumento(tipov,&porc_aum);
    //ROUNDS GANADOS TOTALES POR PELEADOR
    printf("El peleador de la esquina roja gano %i rounds en total y perdio %i, y el peleador de la esquina azul gano %i rounds en total y perdio %i\n", rounds_totales[0],36-rounds_totales[0], rounds_totales[1],36-rounds_totales[1]);
    switch(ganador){
        case 1:
            printf("El ganador del combate fue el peleador de la esquina roja con %i puntos, el perdedor obtuvo %i puntos\n",punt1,punt2);
            //DINERO GANADO POR BOXEADOR
            ganancias[0]=b_inicial+((b_inicial*porc_aum)*rounds_totales[0]);
            ganancias[1]=b_inicial-(b_inicial*0.4);
            break;
        case 2:
            printf("El ganador del combate fue el peleador de la esquina azul con %i puntos, el perdedor obtuvo %i puntos\n",punt2,punt1);
            //DINERO GANADO POR BOXEADOR
            ganancias[1]=b_inicial+((b_inicial*porc_aum)*rounds_totales[1]);
            ganancias[0]=b_inicial-(b_inicial*0.4);
            break;
        default:
            printf("El combate termino en un empate");
    }
}