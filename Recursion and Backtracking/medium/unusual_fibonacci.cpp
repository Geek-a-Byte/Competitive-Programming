#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define N 100005
int dp[N];
int a,b;
int fib(int n) {
        // fib -> 0 1 1 2 3
        // pos -> 1 2 3 4 5
        if(dp[n]!=-1) return dp[n];
        if(n==1) return dp[n]=a;
        if(n==2) return dp[n]=b;
        else return dp[n]=(fib(n-1)%1000000007+fib(n-2)%1000000007)%1000000007;
}

signed main()
{
   int q;
   cin>>a>>b>>q;
   memset(dp,-1,sizeof(dp));
   while(q--){
     int n;
     cin>>n;
     cout<<fib(n)<<endl;
   }
}
