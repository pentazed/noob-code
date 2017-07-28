/*
    Amit Kumar
    28-July-2016
*/



#include<stdio.h>

void insertionSort(int arr[], int n);

//function: main
int main(){
  int n, i;
  printf("Enter n: ");
  scanf("%d\n", &n);
  int arr[n];
  for(i=0; i<n; i++){
    scanf("%d", &arr[i]);
  }

  insertionSort(arr, n);

  for(i=0; i<n; i++){
    printf("%d\n", arr[i]);
  }
}
//end of function: main

//function:insertionSort
void insertionSort(int arr[], int n){
  int i,j, key;
  for(j=1; j<n; j++){
    key = arr[j];
    i = j-1;
    while (i>=0 && arr[i] > key) {
      arr[i+1] = arr[i];
      arr[i] = key;
      i--;
    }
  }
}
//end of function: insertionSort
