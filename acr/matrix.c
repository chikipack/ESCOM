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
    printf("filas de A: %d\n",filas_A);
    printf("columnas de A: %d\n",colum_A);
    printf("filas de B: %d\n",filas_B);
    printf("columnas de B: %d\n",colum_B);
    
    //llenamos las matricez con valores aleatorios
    int matrixA[filas_A][colum_A];
    int matrixB[filas_B][colum_B];

    for (int i = 0; i < filas_A; i++){
        for (int j = 0; j < colum_A; j++){
            printf("digite el numero en la posicion %d %d  ",i,j);
            scanf("%d",&matrixA[i][j]);
        }
    }
    for (int i = 0; i < filas_A; i++){
        printf("\n");
        for (int j = 0; j < colum_A; j++){
            printf("%d",matrixA[i][j]);
        }
        
    }
    return 0;
}