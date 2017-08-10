#include<stdio.h>
int min(int a, int b)
{
    if(a>b)
        return b;
    else
        return a;
}
void main()
{
    int n,N,i,j;
    printf("Enter the no of changes : ");
    scanf("%d",&n);
    printf("\nEnter the amount you want to get change of : ");
    scanf("%d",&N);
    int d[n+1],c[n+1][N+1];
    printf("\nEnter the value of changes : ");
    for(i=1; i<n+1; i++)
    {
        printf("\nd[%d] = ",i);
        scanf("%d",&d[i]);
    }
    //Initialization of first row and column
    for(i=0;i<n+1;i++)
        c[i][0] = 0;
    for(j=0;j<N+1;j++)
        c[0][j] = j;

    //Condition for table
    for(i=1;i<n+1;i++)
    {
        for(j=1;j<N+1;j++)
        {
            if(i==1 && j<d[i])
                c[i][j] =90 ;
            else if(d[i]==c[0][j])
                c[i][j]=1;
            else if(i==1)
                c[i][j] = 1 + c[i][j-d[i]];
            else if(j<d[i])
                c[i][j] = c[i-1][j];
            else
                c[i][j] = min(c[i-1][j],1+c[i][j-d[i]]);
        }
    }
    //Printing
    printf("\n");
    for(j=0;j<N+1;j++)
        printf("%d\t",j);
    printf("\n------------------------------------------------------------------\n");
    for(i=1;i<n+1;i++)
    {
        for(j=0;j<N+1;j++)
        {
            if(c[i][j]>=90)
                printf("NP\t");
            else
            printf("%d\t",c[i][j]);
        }
        printf("\n");
    }
    printf("\n\nThe minimum no of change required for the value %d is : %d\n",N,c[i-1][j-1]);
}
