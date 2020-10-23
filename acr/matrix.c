#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int filas_A,colum_A, filas_B, colum_B,numero_hilos;

int main(int argc, char *argv[]){
    srand(time(NULL));

    
    printf("ingresa las filas de la matriz A\n");
    scanf("%d",&filas_A);
    printf("ingresa las columnas de la matriz A\n");
    scanf("%d",&colum_A);
    printf("\nNOTA: para que la multiplicacion sea valida las filas de B deben ser las mismas que las columnas de A\n");
    printf("por lo que el valor ingresado en columnas de A sera el mismo valor que las filas de B\n\n");
    filas_B = colum_A;
    printf("ingresa las columnas de la matriz B\n");
    scanf("%d",&colum_B);
    printf("filas de A: %d\n",filas_A);
    printf("columnas de A: %d\n",colum_A);
    printf("filas de B: %d\n",filas_B);
    printf("columnas de B: %d\n",colum_B);
    printf("Cuantos hilos quieres usar? NOTA el numero de hilos debe ser menor o igual que las filas de A\nNumero recomendado de hilos:%d\n",filas_A);
    scanf("%d",&numero_hilos);
    while(numero_hilos > filas_A){
        printf("porfavor, el numero de hilos debe ser menor o igual que la cantidad de filas de A\nNumero recomendado:%d\n",filas_A);
        scanf("%d",&numero_hilos);
    }
    
    
    //llenamos las matricez con valores aleatorios
    int matrixA[filas_A][colum_A];
    int matrixB[filas_B][colum_B];

    for (int i = 0; i < filas_A; i++){
        for (int j = 0; j < colum_A; j++){
            matrixA[i][j] = rand()%6;
            //scanf("%d",&matrixA[i][j]);
        }
    }
    for (int i = 0; i < filas_A; i++){
        printf("\n");
        for (int j = 0; j < colum_A; j++){
            printf("%d",matrixA[i][j]);
        }
    }
    printf("\n");

    for (int i = 0; i < filas_B; i++){
        for (int j = 0; j < colum_B; j++){
            matrixB[i][j] = rand()%6;
            //scanf("%d",&matrixA[i][j]);
        }
    }
    for (int i = 0; i < filas_B; i++){
        printf("\n");
        for (int j = 0; j < colum_B; j++){
            printf("%d",matrixB[i][j]);
        }
    }
    printf("\n");
    return 0;
}