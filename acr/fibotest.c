#include <stdio.h>
#include <stdlib.h>

int main(){
    int val_max;
    int a=0, b=1,c;
    printf("introduce hasta que numero quieres llegar\n");
    scanf("%d",&val_max);//supongamos val_max = 20
    do
    {
        c=a+b;
        if (c > val_max)
        {
            break;
        }
        
        printf("%d-",c);
        a=b;
        b=c;
    } while (c <= val_max);

}