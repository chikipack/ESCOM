#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int input_check(int input);
int numThread_check(int num_thread, int rowOfA);
int matrixA[][],matrixB[][],matrixC[][];

int main(int argc, char * argv[]) {
    srand(time(NULL));//random values function
    if (input_check(argc) == -1){
        return -1;
    }
    int rowA = atoi(argv[1]);
    int colA = atoi(argv[2]);
    int rowB = atoi(argv[3]);
    int colB = atoi(argv[4]);
    int num_threads = atoi(argv[5]);
    if(numThread_check (num_threads, rowA) == -1){
        return -1;
    }
    int rowC = rowA;
    int colC = colB;
    return 0;
}

int input_check(int input){
    if (input!=6){
        printf("ERROR: invalid input data\n");
        printf("input data format: <RowA> <ColA> <RowB> <ColB> <numThreads>\n");
        return -1;
    }
}

int numThread_check(int num_thread, int rowOfA){
    if (num_thread <= rowOfA){
        return 0;
    }else{
        printf("number of threads must be smaller/equals to rows of matrix A \n");
        return -1;
    }
    
}