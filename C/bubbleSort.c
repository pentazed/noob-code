/*
    Amit Kumar
    28-July-2016
*/


//this is an implementation of the bubbleSort algorithm
#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int [], int );

int main(){
    int n, *x;
    printf("Enter the lengh of the array to be sorted: ");
    scanf("%d", &n);

    x = (int *)malloc(n*sizeof(n));

    //reading the integer array
    for(int i=0; i<n; i++){
        scanf("%d", &x[i]);
    }

    bubbleSort(x, n);
}

void bubbleSort(int x[], int n){
    int hold, j, pass;
    int switched = 1;

    for(pass = 0; (pass < n-1) && (switched == 1); pass++){
        switched = 0;
        for(j=0; j<n-pass-1; j++){
            if(x[j] > x[j+1]){
                switched = 1;
                hold = x[j];
                x[j] = x[j+1];
                x[j+1] = hold;
            }
        }
    }

    for(int k=0; k<n; k++){
        printf("%d ", x[k]);
    }
}
