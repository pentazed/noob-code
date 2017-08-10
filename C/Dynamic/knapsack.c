#include<stdio.h>
int max(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}
void main()
{
    int n,W,i,j;
    printf("Enter the no of items : ");
    scanf("%d",&n);
    printf("\nEnter the max weight allowed : ");
    scanf("%d",&W);
    int va[n+1],w[n+1],v[n+1][W+1];
    printf("\nEnter the value and weight of each item : ");
    for(i=1; i<n+1; i++)
    {
        printf("object[%d] = ",i);
        scanf("%d%d",&va[i],&w[i]);
    }
    for(i=0;i<n+1;i++)
        v[i][0] = 0;
    for(j=0;j<W+1;j++)
        v[0][j] = j;
    for(i=1;i<n+1;i++)
    {
        for(j=1;j<W+1;j++)
        {
            if(i==1 && j<w[i])
                v[i][j] = 0;
            else if(i==1)
                v[i][j] = va[i];
              else if(j==w[i])
                v[i][j] = va[i];
            else if(j<w[i])
                v[i][j] = v[i-1][j];
            else
                v[i][j] = max(v[i-1][j],va[i]+v[i-1][j-w[i]]);
        }
    }
    //Printing
    printf("\n");
    for(j=0;j<W+1;j++)
        printf("%d\t",j);
    printf("\n--------------------------------------------------------------------------------\n");
    for(i=1;i<n+1;i++)
    {
        for(j=0;j<W+1;j++)
        {
          printf("%d\t",v[i][j]);
        }
        printf("\n");
    }

}

