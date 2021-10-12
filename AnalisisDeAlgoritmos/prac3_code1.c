#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* 
*  los siguientes tres algoritmos calculan el cociente de dos enteros positivos
*  n=div*q+res 
*  realizar el analisis a priori y a posteriori de cada algoritmo
*/

int division1(int nEntrada, int divEntrada){
    int contador=5;
    int n=nEntrada;
    int div=divEntrada;
    int res=0;
    int q = 0;
    printf("%d",n);
    while(n>=div){
        contador++;
        contador++;
        n=n-div; contador++;
        q=q+1; contador++;
    }
    res=n; contador++;
    printf(" = %d * %d + %d\n",div,q,res);contador++;
    contador++;
    printf("pasos: %d\n",contador);
    return q;
}

int division2(int nEntrada, int divEntrada){
    int contador=4;
    int dd = divEntrada;
    int q=0;
    int r = nEntrada;
    
    printf("%d",nEntrada);
    while(dd<=nEntrada){
        contador++;
        contador++;
        dd=2*dd; contador++;
    }
    while(dd>divEntrada){
        contador++;
        contador++;
        dd=dd/2; contador++;
        q=2*q; contador++;
        contador++;
        if (dd<=r){
            contador++;
            r=r-dd; contador++;
            q=q+1; contador++;
        }        
    }
    printf(" = %d * %d + %d\n",dd,q,r);
    printf("pasos: %d\n",contador);
    return q;
}

int contadorDiv3=0;
int division3(int nEntrada, int divEntrada){
    contadorDiv3++;
    if (divEntrada>nEntrada){
        contadorDiv3++;
        printf("pasos: %d\n",contadorDiv3);
        return 0;
    }else{
        contadorDiv3++;
        contadorDiv3++;
        return 1+division3(nEntrada-divEntrada,divEntrada);
    }
}

int main(int argc, char *argv[]){
    int n=atoi(argv[1]);
    int div=atoi(argv[2]);
    //int res=atoi(argv[3]);

    printf("Division 1: %d \n",division1(n,div));
    printf("///////////////////////////////////////\n");
    printf("Division 2: %d \n",division2(n,div));
    printf("///////////////////////////////////////\n");
    printf("Divison 3: %d",division3(n,div));
}

