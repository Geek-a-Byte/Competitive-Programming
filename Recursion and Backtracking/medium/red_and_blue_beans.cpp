#include<bits/stdc++.h>
using namespace std;
#define int long long int
signed main()
{
   int t;
   cin>>t;
   while(t--){
       int r,b,d;
       cin>>r>>b>>d;
       int min=r<b?r:b;
       if(b>(d+1)*min or r>(d+1)*min)
       {
           cout<<"No\n";
       }
       else
       {
           cout<<"Yes\n";
       }
   }
}
