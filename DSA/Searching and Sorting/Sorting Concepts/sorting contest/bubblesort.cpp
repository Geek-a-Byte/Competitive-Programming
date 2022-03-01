#include<stdio.h>
int main()
{
    int n,sum=0,i;
    int total=0;
    scanf("%d",&n);
    int a[100];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    for(int j=0;j<n-1;j++)
    {
        for(int k=0;k<n-j-1;k++)
        {
            if(a[k]<a[k+1])
            {
                int swap;
                swap=a[k];
                a[k]=a[k+1];
                a[k+1]=swap;
            }         
        }
    }
    for(i=0;i<n;i++)
    {
        total+=a[i];
        if(total>sum-total)
            break;
    }
    printf("%d",i+1);
}
