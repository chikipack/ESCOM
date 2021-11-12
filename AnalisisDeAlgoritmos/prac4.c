#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main(){
    int contador=0;//Esta variable nos va a decir el tamanio de la matriz
    char caracterLeido;//el caracter leido por fgetc nos va a ayudar para saber cuando hay un '\n'
    const char* filename = "asciiarrow.txt";//el archivo de texto con la matriz ascii
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

}