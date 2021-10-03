#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int fibo(int n);

int main(){
    int posicion;
    printf("ingrese hasta que posicion de la serie quiere ingresar\n");
    scanf("%d",&posicion);
    int valorPosicion = fibo(posicion);
    printf("%d",valorPosicion);
}

int fibo(int n){
    if(n>1){
        return fibo(n-1)+fibo(n-2);
    }else if (n==0){
        return 0;
    }else{
        return 1;
    }
    
}