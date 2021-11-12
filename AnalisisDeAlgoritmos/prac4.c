#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main(){
    int contador=0;//Esta variable nos va a decir el tamanio de la matriz
    char caracterLeido;//el caracter leido por fgetc nos va a ayudar para saber cuando hay un '\n'
    const char* filename = "artii64.txt";//el archivo de texto con la matriz ascii
    FILE* input_file=fopen(filename,"r");
    if (!input_file){
        printf("error al abrir el archivo\n");
        exit(EXIT_FAILURE);
    }
    do{
        caracterLeido=fgetc(input_file);
        if (caracterLeido=='\n'){
            printf("\nel tamnio de la matriz es: %dx%d\n",contador,contador); 
            break;
        }
        printf("%c",caracterLeido);
        contador++;
    } while (1);
    fclose(input_file);
    int filas=contador;
    int columnas=contador;
    input_file=fopen(filename,"r");
    char matrix[filas][columnas];
    for (int i = 0; i <= filas; i++){
        for (int j = 0; j <= columnas; j++){
            matrix[i][j]=fgetc(input_file);
            if (matrix[i][j]==EOF){
                break;
            }
            printf("%c",matrix[i][j]);
        }
    }

    for(int capa=0; capa<filas/2;capa++){
        int first=capa;
        int last=filas-1-capa;
        for (int i = capa; i < last; i++) {
                int offset=i-first;
                int top = matrix[first][i];
                
                //left -> top
                matrix[first][i]=matrix[last-offset][first];
                
                //bottom -> left
                matrix[last-offset][first]=matrix[last][last-offset];
                
                //right -> bottom
                matrix[last][last-offset]=matrix[i][last];
                
                //top-> right
                matrix[i][last]=top;
                }
    }
    printf("\n");
    printf("\n");
    for (int i = 0; i < filas; i++){
        for (int j = 0; j <columnas; j++){
            printf("%c",matrix[i][j]);
        }
        printf("\n");
    }


   


}