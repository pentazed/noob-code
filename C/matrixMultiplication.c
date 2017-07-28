/*
    Amit Kumar
    28-July-2016
*/



#include<stdio.h>

int main(){
  int aRow, aCol, bRow, bCol, cRow, cCol;
  int A[100][100], B[100][100], C[100][100];
  int i, j, k;
  printf("Enter row and column of A; ");
  scanf("%d %d", &aRow, &aCol);
  printf("Enter row and columns of B: ");
  scanf("%d %d", &bRow, &bCol);

  
  //reading the first matrix
  for(i=0; i<aRow; i++){
    for(j=0; j<aCol; j++){
      scanf("%d", &A[i][j]);
    }
  }

  //reading the second matrix
  for(i=0; i<bRow; i++){
    for(j=0; j<bCol; j++){
      scanf("%d", &B[i][j]);
    }
  }

  //calculating the product
  cRow=aRow;
  cCol=bCol;
  for(i=0; i<cRow; i++){
    for(j=0; j<cCol; j++){
      C[i][j] = 0;
      for(k=0; k<cCol; k++){
        C[i][j] += A[i][k]*B[k][j];
      }
    }
  }

  //printing the product
  for(i=0; i<cRow; i++){
    for(j=0; j<cCol; j++){
      printf("%d ", C[i][j]);
    }
    printf("\n");
  }

}
