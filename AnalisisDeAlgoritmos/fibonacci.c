#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int a=0;
    int b=1;
    int c=0;
    int numero_max;
    printf("Ingresa un numero entero\n");
    scanf("%d",&numero_max);
    do{
        printf("%d, ",c);
        c=a+b;
        if (c > numero_max){
            break;
        }
        a=b;
        b=c;
    } while (c <= numero_max);    
}