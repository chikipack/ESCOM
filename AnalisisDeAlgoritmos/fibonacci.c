#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    
}

void * fibo (void *arg){
    int a=0;
    int b=1;
    int c;
    int numero_max = *((int*)arg);
    if (numero_max == 0){
        printf("la serie fibo es: 0\n");
    }else if (numero_max == 1){
        printf("la serie fibo es: 0,1\n");
    }else{
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
    }    
}