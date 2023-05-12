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
const int mod = 100000007;


void fileOJ()
{
#ifndef ONLINE_JUDGE
    IO
#endif
}

int fn(int id, vector<int>&v, vector<int>& dp)
{
    if(id==0) return 0;
    if(dp[id]!=-1) return dp[id];
    int l=fn(id-1,v,dp)+abs(v[id]-v[id-1]);
    int r=INT_MAX;
    if(id>1) r=fn(id-2,v,dp)+abs(v[id]-v[id-2]);
    return dp[id]=min(l,r);
}


signed main()
{
    fast
    fileOJ();
    int n;
    cin>>n;
    vector<int>dp(n+1, -1);
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cout << fn(n-1, v, dp);
    return 0;
}