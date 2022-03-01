
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    multiset<int> a;
    int x;
    while (1)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;

        for (int i = 0; i < n; i++)
        {
            cin >> x;
            a.insert(x);
        }
        for (int i = 0; i < m; i++)
        {
            cin >> x;
            a.insert(x);
        }
        int c = 0;
        for (auto i : a)
        {
            if (!(a.count(i) > 1))
            {
                c++;
            }
        }
        cout << (a.size() - c) / 2;

        a.clear();
    }
}