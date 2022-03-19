#include <bits/stdc++.h>
using namespace std;
#define int long long int

int steps;
void count(int a,int b)
{
    //complexity logn
    //cout<<a<<" "<<b<<endl;
    //base case -> if b==0, we would not be able to get to (1,1)
    //base case -> if b==1, the steps count would be simply a-1;
    //else (5,2)->(5-2,2)->(3-2,2) in 5/2 steps or (5,2)->(5%2,2)
    if(b==0)
    {
        steps=INT_MAX; return;
    }
    if(b==1)
    {
        steps+=a-1; return;
    }
    else
    {
        steps+=a/b;
        count(b, a%b);
    }
}
 
int fn(int n)
{
    //complexity n
    if(n==1) return 0;
    int ans=INT_MAX;
    for(int i=1;i<n;i++)
    {
        steps=0;
        count(n,i);
        ans=min(ans,steps);
    }
    return ans;
}
 
signed main()
{
   int n;
   cin>>n;
   cout<<fn(n);
}
