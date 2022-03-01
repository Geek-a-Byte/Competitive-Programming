#include<iostream>
using namespace std;

void insertion_sort(int array[],int size)
{
    for(int i=1;i<size;i++)
    {
        int temp,j;
        temp=array[i];
        j=i-1;
        while(j>=0 && array[j]>temp)
        {
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=temp;
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
    insertion_sort(a,n);
    
    int sum=0,diff;
    for(int i=0;i<n;i=i+2)
    {
        diff=a[i+1]-a[i];
        sum+=diff;
    }
    cout<<sum<<endl;
}