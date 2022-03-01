#include<bits/stdc++.h>
#include<cstring>
using namespace std;

int main()
{
   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++)
   {
       cin>>a[i];
   }
   sort(a,a+n);

   
   int count[1001]={0};

   for(int i=0;i<n;i++)
   {
           count[a[i]]++;
   }

  
   sort(count,count+1001,greater<int>());
   
   
 cout<<count[0]<<" ";
   
   int c=0;
    for(int i=0;count[i]>0;i++)
    {
       if(count[i]>=1)
       {
           c++;
       }

   }
   cout<<c;


}