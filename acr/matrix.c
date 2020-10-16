#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int filas_A,colum_A, filas_B, colum_B;
    printf("ingresa las filas de la matriz A\n");
    scanf("%d",&filas_A);
    printf("ingresa las columnas de la matriz A\n");
    scanf("%d",&colum_A);
    printf("NOTA: para que la multiplicacion sea valida las filas de B deben ser las mismas que las columnas de A\n");
    printf("por lo que el valor ingresado en columnas de A sera el mismo valor que las filas de B\n");
    filas_B = colum_A;
    printf("ingresa las columnas de la matriz B\n");
    scanf("%d",&colum_B);
    
    

}