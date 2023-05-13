#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define read freopen("input.txt", "r", stdin);
#define write freopen("output.txt", "w", stdout);
#define IO read write
#define TC int tc; cin >> tc; for (int cn = 1; cn <= tc; ++cn)
#define rep(i,n) for(int i = 0; i < n; i++)

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
// const int mod = 100000007;


void fileOJ()
{
#ifndef ONLINE_JUDGE
    IO
#endif
}
int mod=1e9+7;

int f(int s, int e, vector<vector<int>>& dp, vector<vector<int>>& grid)
{
    if(s>=0 and e>=0 and grid[s][e]==1)
    {
        return 0;
    }
    if(s==0 and e==0)
    {
        return 1;
    }
    if(s<0 or e<0)
    {
        return 0;
    }
    if(dp[s][e]!=-1) return dp[s][e];
    int up=f(s-1, e, dp, grid);
    int left=f(s, e-1, dp, grid);
    return dp[s][e]=(up+left)%mod;
}
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int n=obstacleGrid.size();
    int m=obstacleGrid[0].size();
    vector<vector<int>>dp(n, vector<int>(m, -1));
    return f(n-1, m-1, dp, obstacleGrid); 
}

signed main()
{
    fast
    fileOJ();
    int n;
    cin>>n;
    vector<vector<int>>grid(n, vector<int>(n));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            char c;
            cin>>c;
            if(c=='.')
            {
                grid[i][j]=0;
            }
            else if(c=='*')
            {
                grid[i][j]=1;
            }
        }
        
    }
    cout<<(uniquePathsWithObstacles(grid))%mod;
}