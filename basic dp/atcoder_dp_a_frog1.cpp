#include <bits/stdc++.h>
using namespace std;

#define TC     \
    int tc;    \
    cin >> tc; \
    for (int cn = 1; cn <= tc; ++cn)
#define mx 10000000
int dp[mx];
int fn(vector<int> v)
{
    for (int i = 2; i < v.size(); i++)
    {
        dp[i] = min(dp[i - 2] + abs(v[i - 2] - v[i]), dp[i - 1] + abs(v[i - 1] - v[i]));
    }
    return dp[v.size() - 1];
}

int main()
{
    memset(dp, -1, sizeof(dp));
    vector<int> v;
    TC
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    dp[0] = 0;
    dp[1] = abs(v[0] - v[1]);
    cout << fn(v);
    return 0;
}
