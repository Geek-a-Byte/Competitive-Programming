#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define mx 50
int dp[mx];

int fn(int n)
{
    if (n == 1 or n == 2)
        return dp[n] = 2;
    if (dp[n] != -1)
        return dp[n];
    else
        return dp[n] = fn(n - 1) + fn(n - 2);
}
signed main()
{
    int n;
    while (cin >> n)
    {
        memset(dp, -1, sizeof(dp));
        cout << fn(n);
    }
}
