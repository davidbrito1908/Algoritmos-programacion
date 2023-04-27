#include <stdio.h>

const int n=3; //Tamaño de las matrices nxn --> 3x3

void leer(int mat[n][n]);
int suma(int a, int b);
void imprimir(int mat[n][n]);


// VARIABLES GLOBALES
int i,j,a,b;

void main(){
    int mat1[n][n],mat2[n][n],mat3[n][n];
    leer(mat1);
    leer(mat2);

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            mat3[i][j]=suma(mat1[i][j],mat2[i][j]); 
        }  
    }
    imprimir(mat3);
}

void leer(int mat[n][n]){
    printf("MATRIZ 1\n");
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf("Ingrese el numero de la posicion (%i, %i): ", i,j);
            scanf("%i", &mat[i][j]);
        }
    }    
}

int suma(int a, int b){
    return(a+b);
}

void imprimir(int mat[n][n]){
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf("El elemento en la posicion (%i, %i) es: %i\n", i,j, mat[i][j]);
        }
    }    
}