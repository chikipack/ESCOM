#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int *valorDia;
    struct nodo *sig;
}conjuntoSolucion;

conjuntoSolucion *soluciones(conjuntoSolucion *lista){
    lista=NULL;
    return lista;
}

conjuntoSolucion *agregarSolicion(conjuntoSolucion *lista,int *valor){
    conjuntoSolucion* nuevaSolucion,*aux;
    nuevaSolucion = (conjuntoSolucion*)malloc(sizeof(conjuntoSolucion));
    nuevaSolucion->valorDia=valor;
    nuevaSolucion->sig = NULL;
    if(lista == NULL){
        lista = nuevaSolucion;
    }else{
        aux = lista;
        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevaSolucion;
    }
    return lista; 
}

int main(){
    
    int diasApertura[]={0,29,36,50,52,66,71,85,100,117,127,129};//el conjunto S
    int CantidadDiasApertura=sizeof(diasApertura)/4;//numero de elementos en el arreglo diasApertura[]
    int diasQueDuraElFertilizante=30;//dias que dura el fertilizante = r
    int diaQueSeAcabaElFertilizante=diasApertura[0]+diasQueDuraElFertilizante;//varible f
    /*
    tomamos di al dia de visita en el que nos encontramos, la siguiente visita es dj, donde el maximo valor de dj es dj-di<=diasQueDuraElFertilizante
    dj-di<=diasQueDuraElFertilizante y dj+1 > diasQueDuraElFertilizante
    */
    conjuntoSolucion *ListaSoluciones = soluciones(ListaSoluciones);
    ListaSoluciones = agregarSolicion(ListaSoluciones,0);// Estas dos lineas son las que agregas solciones
    //ListaSoluciones = agregarSolicion(ListaSoluciones,29);//al conjunto solucion, la funcion agregarSolucion es la que usaremos apra agregar elem a la lista
    //printf("%d\n",ListaSoluciones->valorDia);
    int k=1;
    int k2=1;
    while (k < CantidadDiasApertura){
        printf("%d<%d?\n\n",k,CantidadDiasApertura);
        while(diasApertura[k]<diaQueSeAcabaElFertilizante && k<CantidadDiasApertura){
            printf("%d<%d?\n",diasApertura[k],diaQueSeAcabaElFertilizante);
            printf("aun nos quedan %d dias de fertilizante\n\n",diaQueSeAcabaElFertilizante-diasApertura[k]);
            k++;
        }
        ListaSoluciones = agregarSolicion(ListaSoluciones,diasApertura[k-1]);
        if (k==CantidadDiasApertura){
            break;
        }
        diaQueSeAcabaElFertilizante=diasApertura[k-1]+diasQueDuraElFertilizante;
        printf("Ahora tenemos fertilizante hasta el dia %d\n",diaQueSeAcabaElFertilizante);
        printf("k=%d    [k]%d\n",k,diasApertura[k]);
    }
    //ListaSoluciones = agregarSolicion(ListaSoluciones,diasApertura[k]);
    

    while (ListaSoluciones != NULL){
        printf("%d,",ListaSoluciones->valorDia);
        ListaSoluciones = ListaSoluciones->sig;
    }
    
    return 0;
}