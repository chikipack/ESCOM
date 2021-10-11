#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* 
*  los siguientes tres algoritmos calculan el cociente de dos enteros positivos
*  n=div*q+res 
*  realizar el analisis a priori y a posteriori de cada algoritmo
*/

int division1(int nEntrada, int divEntrada){
    int n=nEntrada;
    int div=divEntrada;
    int res=0;
    int q = 0;
    printf("%d",n);
    while(n>=div){
        n=n-div; 
        q=q+1;
    }
    res=n;
    printf(" = %d * %d + %d\n",div,q,res);
    return q;
}

int division2(int nEntrada, int divEntrada){
    int dd = divEntrada;
    int q=0;
    int r = nEntrada;
    
    printf("%d",nEntrada);
    while(dd<=nEntrada){
        dd=2*dd;
    }
    while(dd>divEntrada){
        dd=dd/2;
        q=2*q;
        if (dd<=r){
            r=r-dd;
            q=q+1;
        }        
    }
    printf(" = %d * %d + %d\n",dd,q,r);
    return q;
}

int division3(int nEntrada, int divEntrada){
    if (divEntrada>nEntrada){
        return 0;
    }else{
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

