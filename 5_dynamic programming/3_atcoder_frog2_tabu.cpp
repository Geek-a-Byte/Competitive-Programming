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

int dp[N];
int n,k;


void fileOJ()
{
#ifndef ONLINE_JUDGE
    IO
#endif
}

void fn(vector<int>& v, vector<int>& dp, int k)
{
    for (int i = 2; i < v.size(); i++)
    {
        int min_steps = INT_MAX;
        for(int j = 1; j <= k; j++){
            int fs = INT_MAX;
            if(i>=j) 
            { 
                fs = dp[i - j] + abs(v[i - j] - v[i]);
                min_steps = min(min_steps,fs);
                // cout<<min_steps<<endl;
            }
        }
        dp[i] = min_steps;
    }
}

signed main()
{
    fileOJ();
    cin>>n>>k;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    vector<int>dp(n, -1);
    dp[0] = 0;
    dp[1] = abs(v[0] - v[1]);
    fn(v,dp,k);
    // for(auto i:dp) cout<<i<<" ";
    cout<<dp[n-1];
    return 0;
}
