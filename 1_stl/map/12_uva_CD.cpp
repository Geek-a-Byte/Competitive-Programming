#include <bits/stdc++.h>
using namespace std;

int main()
{
    long n, m, x;

    while (1)
    {
        map<long, long> mp;
        long count = 0;
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;

        for (long i = 0; i < n; i++)
        {
            cin >> x;
            mp[x] = 1;
        }
        for (long i = 0; i < m; i++)
        {
            cin >> x;
            if (mp[x] == 1)
                count++;
        }
        cout << count << endl;
    }
}