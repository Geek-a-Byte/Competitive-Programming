#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define mx 100005
int dp[mx][3];
signed main()
{
    int n;
    cin >> n;
    int a[n + 1], b[n + 1], c[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    dp[1][1] = a[1];
    dp[1][2] = b[1];
    dp[1][3] = c[1];
    for (int j = 2; j <= n; j++)
    {
        dp[j][1] += a[j] + max(dp[j - 1][2], dp[j - 1][3]);
        dp[j][2] += b[j] + max(dp[j - 1][1], dp[j - 1][3]);
        dp[j][3] += c[j] + max(dp[j - 1][2], dp[j - 1][1]);
    }
    cout << max(dp[n][1], max(dp[n][2], dp[n][3]));
    return 0;
}