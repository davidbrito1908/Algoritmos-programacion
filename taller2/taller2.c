#include <stdio.h>
#define maximo 100

//FUNCIONES
float total_ventas(float categoria, int lineas);

float matriz[maximo][3];

void main(){
    //VARIABLES
    int i, lineas=0;
    float cat,cant,precio,total_cat[3], ventas_total;
    FILE *arch_entrada,*arch_salida;
    //ABRIR ARCHIVO DE LECTURA
    arch_entrada=fopen("ventas.txt","r");
    if(arch_entrada==NULL){
        return; //No existe el archivo
    }
    //LLENAR MATRIZ
    while(!feof(arch_entrada) && (lineas<maximo)){
        fscanf(arch_entrada,"%f, %f, %f\n", &cat,&cant,&precio);
        matriz[lineas][0]=cat;
        matriz[lineas][1]=cant;
        matriz[lineas][2]=precio;
        printf("%f %f %f\n", matriz[lineas][0],matriz[lineas][1],matriz[lineas][2]);
        lineas++;
    }
    //TOTAL DE VENTAS POR CATEGORIA
    total_cat[0]=total_ventas(1,lineas);
    total_cat[1]=total_ventas(2,lineas);
    total_cat[2]=total_ventas(3,lineas);

    //VENTAS TOTALES
    ventas_total= total_cat[0] + total_cat[1] + total_cat[2];

    //MOSTRAR RESULTADOS POR PANTALLA
    printf("\nVentas totales por categoria:\n");
    for(i=0;i<3;i++){
        printf("Categoria %i: $%f\n", i+1, total_cat[i]);
    }
    printf("Ventas totales: $%f\n", ventas_total);

    //ESCRIBIR AL ARCHIVO DE SALIDA
    arch_salida=fopen("ventas_totales.txt","w");
    fprintf(arch_salida, "Ventas totales por categoria:\n");
    for(i=0;i<3;i++){
        fprintf(arch_salida, "Categoria %i: $%f\n", i+1, total_cat[i]);
    }
    fprintf(arch_salida, "Ventas totales: $%f\n", ventas_total);
    //CERRAR ARCHIVO
    fclose(arch_entrada);
    fclose(arch_salida);
}

float total_ventas(float categoria, int lineas){
    int i;
    float total=0;  //ACUMULADOR
    for(i=0;i<lineas;i++){
        if(matriz[i][0]==categoria){
            total+=matriz[i][1]*matriz[i][2]; //CANTIDAD*PRECIO
        }
    }
    return total;
}