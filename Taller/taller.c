#include <stdio.h>
//PROGRAMA REALIZADO POR DAVID BRITO - C.I: 30521360
void main(){
    const int b_inicial=100000; //BOLSA INICIAL

    int i,j,ganador_r, rounds_roja=0,rounds_azul=0,punt1,punt2,caida_r,caida_a,
    total_roja=0,total_azul=0, roja=0,azul=0,empate=0,ganador,victoria,puntaje1=0,puntaje2=0,p_mayor=0,p_menor=120,mayor,menor,
    round_tot_r=0,round_tot_a=0;
    float porc_aum, ganancia1,ganancia2;

    for(i=1;i<4;i++){
        printf("---Puntuacion del Juez %i: ---\n",i);
        for(j=1;j<13;j++){
            printf("--Puntuacion round %i:\n",j);
            //GANADOR DEL ROUND
            do{
                printf("Ingrese el ganador del round (1=Esquina roja, 2=Esquina azul)\n");
                scanf("%i", &ganador_r);
            } while(ganador_r!=1 && ganador_r!=2);

            if(ganador_r==1){
                rounds_roja++;
                punt1=10;
                punt2=9;
            } else{
                rounds_azul++;
                punt2=10;
                punt1=9;       
            }
            //POSIBLE REDUCCION DE PUNTAJE
            do{
                printf("Cayo a la lona el peleador de la esquina roja? (1=Si, 2=No)\n");
                scanf("%i", &caida_r);
            } while(caida_r!=1 && caida_r!=2);            
            do{
                printf("Cayo a la lona el peleador de la esquina azul? (1=Si, 2=No)\n");
                scanf("%i", &caida_a);
            } while(caida_a!=1 && caida_a!=2);

            if(caida_r==1){
                punt1=punt1-2;
            }
            if(caida_a==1){
                punt2=punt2-2;
            }

            printf("PUNTAJE DEL ROUND %i: %i esquina roja y %i esquina azul\n\n",j, punt1,punt2);
            //SUMAR AL PUNTAJE TOTAL
            total_roja+=punt1;
            total_azul+=punt2;
        }
        //ROUND GANADOS SEGUN JUEZ i
        printf("El peleador de la esquina roja gano %i rounds y perdio %i, el peleador azul gano %i rounds y perdio %i\n", rounds_roja,12-rounds_roja,rounds_azul,12-rounds_azul);
        printf("El peleador de la esquina roja sumo %i puntos y el peleador azul sumo %i puntos\n", total_roja,total_azul);
        
        //ACUMULAR ROUNDS GANADOS
        round_tot_r+=rounds_roja;
        round_tot_a+=rounds_azul;
        rounds_roja=0;
        rounds_azul=0;

        //CONTAR RESULTADO DE CADA JUEZ
        if(total_roja>total_azul){
            roja++;
            //VERIFICAR TARJETA MAYOR Y MENOR PUNTUACION
            if(total_roja>p_mayor){
                //MAYOR PUNTUACION
                mayor=i;
                p_mayor=total_roja;
            }
            if(total_azul<p_menor){
                //MENOR PUNTUACION
                menor=i;
                p_menor=total_azul;
            }
        }else{
            if(total_roja==total_azul){
                empate++;
                //VERIFICAR TARJETA MAYOR Y MENOR PUNTUACION
                if(total_roja>p_mayor){
                    //MAYOR PUNTUACION
                    mayor=i;
                    p_mayor=total_roja;
                }else{
                    if(total_roja<p_menor){
                        //MENOR PUNTUACION
                        menor=i;
                        p_menor=total_roja;
                    }
                }

            } else{
                azul++;
                //VERIFICAR TARJETA MAYOR Y MENOR PUNTUACION
                if(total_azul>p_mayor){
                    //MAYOR PUNTUACION
                    mayor=i;
                    p_mayor=total_azul;
                }
                if(total_roja<p_menor){
                    //MENOR PUNTUACION
                    menor=i;
                    p_menor=total_roja;
                }
            }
        }
        //ACUMULAR PUNTAJE TOTAL ENTRE LOS 3 JUECES
        puntaje1+=total_roja;
        puntaje2+=total_azul;
        // REINICIAR TOTAL DE PUNTOS
        total_roja=0;
        total_azul=0;

    }
    //GANADOR ESQUINA ROJA=1
    if(roja>1){
        ganador=1;
        if(azul==1){
            //DIVIDIDA=1
            victoria=1;
        }
        if(roja==3){
            //UNANIME=2
            victoria=2;
        }
        if(empate==1){
            //POR MAYORIA=3
            victoria=3;
        }
    }else{
        //GANADOR ESQUINA AZUL
        if(azul>1){
            ganador=2;
            if(roja==1){
                //DIVIDIDA=1
                victoria=1;
            }
            if(azul==3){
                //UNANIME=2
                victoria=2;
            }
            if(empate==1){
                //POR MAYORIA=3
                victoria=3;
            }

        }else{
            //EMPATE ---> NO CONSIDERADO EN EL ENUNCIADO DEL EJERCICIO
        }
    }

    //TIPO DE VICTORIA
    if(victoria==1){
            printf("Por decision dividida:\n");
            porc_aum=0.05;       
    }else{
        if(victoria==2){
            printf("Por decision unanime:\n");
            porc_aum=0.10;       
        }else{
            printf("Por decision por mayoria:\n");
            porc_aum=0.15;       
        }
    }

    //GANADOR DEL COMBATE
    if(ganador==1){
        printf("El ganador del combate fue el peleador de la esquina roja con %i puntos, el perdedor obtuvo %i puntos\n",puntaje1,puntaje2);
       //DINERO GANADO POR BOXEADOR
       ganancia2=b_inicial-(b_inicial*0.4);
       ganancia1=b_inicial+((b_inicial*porc_aum)*round_tot_r);

    }else{
        if(ganador==2){
            printf("El ganador del combate fue el peleador de la esquina azul con %i puntos, el perdedor obtuvo %i puntos\n",puntaje2,puntaje1);
            //DINERO GANADO POR BOXEADOR
            ganancia1=b_inicial-(b_inicial*0.4);
            ganancia2=b_inicial+((b_inicial*porc_aum)*round_tot_a);
        }else{
            //EMPATE ---> NO CONSIDERADO EN EL ENUNCIADO DEL EJERCICIO
        }
    }
    //ROUNDS GANADOS TOTALES POR PELEADOR
    printf("El peleador de la esquina roja gano %i rounds en total y perdio %i, y el peleador de la esquina azul gano %i rounds en total y perdio %i\n", round_tot_r,36-round_tot_r, round_tot_a,36-round_tot_a);

    //TARJETA CON MAYOR Y MENOR PUNTUACION
    printf("La tarjeta con mayor puntuacion fue la del juez %i, que otorgo %i a uno de los peleadores\n", mayor, p_mayor);
    printf("La tarjeta con menor puntuacion fue la del juez %i, que otorgo %i a uno de los peleadores\n", menor, p_menor);
    //GANANCIA BOXEADORES
    printf("El boxeador de la esquina roja ganara %f dolares y el de la esquina azul ganara %f dolares", ganancia1,ganancia2);
}