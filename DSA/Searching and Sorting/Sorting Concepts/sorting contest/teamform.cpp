#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n],b[n];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int c1=0,c2=0,c3=0;
    int j=0;
    for(int i=0;i<n;i++)
    {
       if(a[i]==1)
       {
           c1++;
           b[j]=i+1;
           j++;
       }

    }
    for(int i=0;i<n;i++)
    {
       if(a[i]==2)
       {
           c2++;
           b[j]=i+1;
           j++;
       }

    }
    for(int i=0;i<n;i++)
    {
       if(a[i]==3)
       {
           c3++;
           b[j]=i+1;
           j++;
       }

    }
    if(c1==0||c2==0||c3==0)
    {
       cout<<"0";
       return 0;
    }
    int min=c1<c2?c1:c2;
    min=min<c3?min:c3;
    int d[min][3];
    int temp1,temp2,temp3;
    temp1=c1,temp2=c2,temp3=c3;
    for(int i=0;i<min;i++)
    {
       
        for(int j=0;j<3;j++)
        {
           
            if(j==0 && c1!=0)
            {
                d[i][j]=b[temp1-1];
                temp1--;
            }
            
            if(j==1 && c2!=0)
            {
                d[i][j]=b[c1+temp2-1];
                temp2--;
            }
            
            if(j==2 && c3!=0)
            {
                d[i][j]=b[c1+c2+temp3-1];
                temp3--;
            }
        }
    }
    cout<<min<<endl;
    for(int i=0;i<min;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<d[i][j]<<" ";
        }
        cout<<endl;
    }
    
}