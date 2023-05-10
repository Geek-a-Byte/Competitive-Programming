#include <bits/stdc++.h>
using namespace std;
#define int long long int

int steps;
set<int>s;
int count(int a,int b)
{
    // cout<<b<<endl;
 
    steps++;
    s.insert(b);
    if(a==b)
    {
        return steps;
    }
    if(b%10==1)
    {
        return count(a,b/10);
    }
    if(b!=0 and b%2==0)
    {
        return count(a,b/2);
    }
    if(a!=b)
    {
        return -1;
    }
}
 
signed main()
{
   int a,b;
   cin>>a>>b;
   if(count(a,b)!=-1){
      cout<<"YES\n";
      cout<<s.size()<<endl;
      for(auto i:s)
      {
          cout<<i<<" ";
      }
   }
   else
   {
       cout<<"NO\n"; 
   }
}
