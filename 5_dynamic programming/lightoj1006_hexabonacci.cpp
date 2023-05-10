#include <bits/stdc++.h>
using namespace std;
#define mod 10000007
#define mx 10005
int a, b, c, d, e, f;
int dp[mx];
int fn(int n)
{
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = fn(n - 1) % mod + fn(n - 2) % mod + fn(n - 3) % mod + fn(n - 4) % mod + fn(n - 5) % mod + fn(n - 6) % mod;
}
int main()
{
    int n, cases;
    cin >> cases;
    for (int caseno = 1; caseno <= cases; ++caseno)
    {
        memset(dp, -1, sizeof(dp));
        cin >> a >> b >> c >> d >> e >> f >> n;
        dp[0] = a;
        dp[1] = b;
        dp[2] = c;
        dp[3] = d;
        dp[4] = e;
        dp[5] = f;
        printf("Case %d: %d\n", caseno, fn(n) % mod);
    }
    return 0;
}
