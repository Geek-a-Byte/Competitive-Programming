//approach 2
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define N 35
int dp[N];
int fib(int n) {
        // fib -> 1 1 2 3 5
        // pos -> 1 2 3 4 5
        if(dp[n]!=-1) return dp[n];
        if(n==0) return dp[n]=0;
        if(n==1) return dp[n]=1;
        else return dp[n]=fib(n-1)+fib(n-2);
}

signed main()
{
   int n;
   cin>>n;
   memset(dp,-1,sizeof(dp));
   cout<<fib(n); 
}
