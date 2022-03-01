#include <bits/stdc++.h>
#define ull unsigned long long
#define PI acos(-1)
#define rep(i, k, n) for (int i = k; i < n; i++)
#define MP(x, y) make_pair(x, y)
#define PB(x) push_back(x)
#define All(p) p.begin(), p.end()
#define CLR(p) memset(p, 0, sizeof(p))
#define ff first
#define ss second
#define sf scanf
#define pf printf
#define PII pair<int, int>
#define M 10000007
#define mod %M
using namespace std;
typedef long long ll;
const ll N=1e4+10;
int dp[N];
int a, b, c, d, e, f;
int fn(int n) {
    if (n == 0) return a;
    if (n == 1) return b;
    if (n == 2) return c;
    if (n == 3) return d;
    if (n == 4) return e;
    if (n == 5) return f;

    int &ret=dp[n];
    if(ret!=-1)
    {
        return ret;
    }
    else
    {
        ret= (fn(n-1) mod + fn(n-2) mod+ fn(n-3) mod + fn(n-4) mod + fn(n-5) mod+ fn(n-6) mod) mod ;
        return ret;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t,n;
    cin>>t;
    for(int i=0; i < t; i++)
    {
        cin>>a>>b>>c>>d>>e>>f>>n;
        memset(dp,-1,sizeof(dp));
        cout<<"Case "<<i+1<<": ";
        cout<<fn(n) mod <<endl;
    }
    
    return 0;
}