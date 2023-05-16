#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define read freopen("input.txt", "r", stdin);
#define write freopen("output.txt", "w", stdout);
#define IO read write
#define TC int tc; cin >> tc; for (int cn = 1; cn <= tc; ++cn)
#define rep(i,n) for(int i = 0; i < n; i++)

#define int long long
#define ll long long int
#define ull unsigned long long int
#define ui unsigned int
#define ld long double

#define pii pair<int, int>
#define stlloop(x) for (__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define CLR(p) memset(p, 0, sizeof(p))
#define sp(x) std::cout << std::fixed << std::setprecision(x)

#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*(b))/gcd(a, b)

#define PI acos(-1)
#define N 10000000
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;


void fileOJ()
{
#ifndef ONLINE_JUDGE
    IO
#endif
}

void solve()
{
    int n;
    cin>>n;
    vector<int>dp(n+1,0);
    // dp(3) -> dp(2)
    dp[0]=dp[1]=1;
    for(int i=2; i<=n; i++)
    {
        for(int j=1; j<=6; j++)
        {
            if(j>i) continue;
            dp[i]=(dp[i]%mod+dp[i-j]%mod)%mod;
        }
    }
    cout<<dp[n]<<endl;
    
}
signed main()
{
    fast
    fileOJ();
    solve();
}