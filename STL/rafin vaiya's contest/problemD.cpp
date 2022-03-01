#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, m, x;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        map<int, int> mp;
        map<int, int> mp1;
        set<int> s;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            s.insert(x);
            mp[x]++;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> x;
            s.insert(x);
            mp1[x]++;
        }
        int c = 0;
        for (auto i : s)
        {
            c += abs(mp[i] - mp1[i]);
        }
        cout << c << endl;
    }
}