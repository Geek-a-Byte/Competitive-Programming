#include <bits/stdc++.h>
using namespace std;

#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define read freopen("input.txt", "r", stdin);
#define write freopen("output.txt", "w", stdout);
#define endl "\n"
#define IO read write
#define int long long int
void fileOJ()
{
#ifndef ONLINE_JUDGE
    IO
#endif
}

signed main()
{
    FIO;
    fileOJ();
    int n;
    cin >> n;
    cout << n << " ";
    while (n != 1)
    {
        if ((n & 1) == 0)
        {
            n = n / 2;
        }
        else
        {
            n *= 3;
            n += 1;
        }
        cout << n << " ";
    }
}