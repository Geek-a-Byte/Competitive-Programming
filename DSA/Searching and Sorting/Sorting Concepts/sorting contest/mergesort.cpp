#include<iostream>
using namespace std;

void merge(int a[],int lb,int mid, int up)
{
    int i=lb;
    int j=mid+1;
    int k=lb;
    int b[up+1];
    while(i<=mid && j<=up)
    {
        if(a[i]<=a[j])
        {
            b[k]=a[i];
            i++;
        }
        else
        {
            b[k]=a[j];
            j++;
        }
        k++;
    }
    if(i>mid)
    {
        while(j<=up)
        {
            b[k]=a[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i<=mid)
        {
            b[k]=a[i];
            i++;
            k++;
        }
    }
    for(int p=lb;p<=up;p++)
    {
        a[p]=b[p];
    }

}
void mergesort(int a[],int lb,int up)
{
    if(lb<up)
    {
        int mid=(lb+up)/2;
        mergesort(a,lb,mid);
        mergesort(a,mid+1,up);
        merge(a,lb,mid,up);
    }
}


int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    mergesort(a,0,n-1);
    int diff;
    int temp;
    int c=0;
    for(int i=0;i<n-1;i++)
    {
        diff=a[i+1]-a[i];
        if(diff!=1)
        {
            temp=a[i+1];
            temp--;
            while(temp!=a[i])
               {
                  c++;
                  temp--;
               }

        }
    }
    cout<<c;
   
   


}