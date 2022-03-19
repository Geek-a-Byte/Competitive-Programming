//https://community.topcoder.com/stat?c=problem_statement&pm=6011
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define N 10000
int dp[N];

int count(int m,int n)
{
    // cout<<m<<" "<<n<<endl;
    if(dp[m]!=-1) return dp[m];
    if(m==n or m<n)
    {
        return dp[m]=1;
    }
    if(m%2==0)
    {
        return dp[m]=count(m/2,n)+count(m/2,n);
    }
    else
    {
        return dp[m]=count(m/2,n)+count((m/2)+1,n);
    }
}
signed main()
{
    int m,n;
    while(cin>>m>>n){
        int ans=0;
        memset(dp,-1,sizeof(dp));
        ans=count(m,n);
        cout<<ans<<endl;
    }
    
}
