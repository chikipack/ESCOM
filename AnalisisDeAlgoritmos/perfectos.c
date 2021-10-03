#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Un número entero positivo es perfecto, si es igual a la suma de sus divisores menores.
// Por ejemplo, 8 no es un número perfecto ya que 8 6 = 1 + 2 + 4, por otro lado, 6 si es
// un número perfecto, ya que 6 = 1 + 2 + 3. Implementar una función Perfecto(n) que
// decida si un número es perfecto o no. Realizar su análisis a priori y a posteriori para la
// función Perfecto(n). Haciendo uso de la función Perfecto(n), implementar una función
// MostrarPerfectos(n) que muestre los n primeros números perfectos. Realizar su análisis
// a posteriori para la función MostrarPerfectos(n). ¿Cuántos números perfectos logro
// generar en su computadora?.

int perfecto(int n){
    int numero=1;
   	int i, sum=0, mul=0;
    int num = n;
	
      	
	for(i=1; i<num; i++) {
		mul=num%i;
		if(mul==0) {
			sum+=i;
		}
	}
        /*sum se compara sum con num, y no con mul */
	if(sum==num){
		printf("El numero %d es perfecto.\n", num);
	}
	return 0;
}

void mostrarPerfecto(){
    int n=1;
    do{
        perfecto(n);
        n++;
    } while (1);
}

int main(){
    mostrarPerfecto();
}