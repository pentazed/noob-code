#include<stdio.h>

void knapsack(int n, float w[], float v[], float We)
{
    float x[n], tp=0, weight=0.0;
    int i=0;
    for(i=0;i<n;i++)
        x[i] = 0.0;
    i=0;
    while(weight<We)
    {
        if((weight+w[i])<=We)
        {
             x[i] = 1.0;
        }
        else
        {
            x[i] = (We-weight)/w[i];
        }
        weight = weight + (x[i]*w[i]);
        tp = tp + (x[i]*v[i]);
        i++;
    }

    printf("\nThe ratio of objects selected is : \n");
   for (i = 0; i < n; i++)
      printf("\nItem[%d] = %f\t",i+1,x[i]);

   printf("\n\nMaximum profit is:- %f", tp);

}
int main()
{
    int n,i,j;
    printf("\nEnter the no of items : ");
    scanf("%d",&n);
    float w[n],v[n],r[n],We,tmp;
    printf("\nEnter the total weight allowed : ");
    scanf("%f",&We);
    printf("Enter the value and weight of each item : \n");
    for(i=0;i<n;i++)
    {
        printf("W[%d] = ",i+1);
        scanf("%f",&w[i]);
        printf("V[%d] = ",i+1);
        scanf("%f",&v[i]);
        r[i] = v[i]/w[i];
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(r[i]<r[j])
            {
                tmp = r[j];
                r[j] = r[i];
                r[i] = tmp;

                tmp = w[j];
                w[j] = w[i];
                w[i] = tmp;

                tmp = v[j];
                v[j] = v[i];
                v[i] = tmp;
            }
        }
    }
    printf("\nThe sorted list according to ratio Vi/Wi : \n");
    for(i=0;i<n;i++){
        printf("\nW[%d] = %f",i+1,w[i]);
        printf("\tV[%d] = %f",i+1,v[i]);
        printf("\tr[%d] = %f\n",i+1,r[i]);
    }
    knapsack(n,w,v,We);
    return 0;
}
