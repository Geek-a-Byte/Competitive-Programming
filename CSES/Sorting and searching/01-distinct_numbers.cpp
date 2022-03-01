#include <bits/stdc++.h>
using namespace std;
#define TC     \
    int tc;    \
    cin >> tc; \
    for (int cn = 1; cn <= tc; ++cn)
#define read freopen("input.txt", "r", stdin);
#define write freopen("output.txt", "w", stdout);
#define int long long int
signed main()
{
    int n;
    cin >> n;
    set<int> s;
    while (n--)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    cout << s.size();
}