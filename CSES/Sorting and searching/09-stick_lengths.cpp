#include <bits/stdc++.h>
using namespace std;

#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"
#define int long long int

signed main()
{
    FIO;
    int n;
    cin >> n;
    // cout << n << " ";
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += abs(v[n / 2] - v[i]);
    }
    cout << s;
}