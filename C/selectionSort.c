/*
    Amit Kumar
    28-July-2016
*/




#include<stdio.h>
#include<stdlib.h>

void selectionSort(int [], int );

int main(){
    int n, *x;
    printf("Enter the length of the array: ");
    scanf("%d", &n);

    x = (int *)malloc(n*sizeof(n));

    //reading the array from the user
    for(int i=0; i<n; i++){
        scanf("%d", &x[i]);
    }

    selectionSort(x, n);
}

void selectionSort(int x[], int n){
    int current, temp, index;

    for(int i=0; i<n-1; i++){
        current = x[i];
        for(int j = i+1; j<n; j++){
            if(x[j] < current){
                current = x[j];
                index = j;
            }
        }
        if(current != x[i]){
            temp = x[i];
            x[i] = x[index];
            x[index] = temp;

        }
    }

    for(int k=0; k<n; k++){
        printf("%d ", x[k]);
    }
}
