#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int a=0;
    int b=1;
    int c;
    int numero_max;
    printf("Ingresa un numero entero\n");
    scanf("%d",&numero_max);
    switch (numero_max){
    case 0:
        printf("la serie fibo es: 0\n");
        break;
    case 1:
        printf("la serie fibo es: 0,1\n");
        break;
    default:
        printf("la serie fibo es: 0, 1, ");
        do{
            c=a+b;
            if (c > numero_max){
                break;
            }
        
            printf("%d, ",c);
            a=b;
            b=c;
        } while (c <= numero_max);
        printf("\n");
        break;
    }
    
    
    
}