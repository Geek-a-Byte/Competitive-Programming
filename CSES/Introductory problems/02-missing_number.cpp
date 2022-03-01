#include <bits/stdc++.h>
using namespace std;

#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define read freopen("input.txt", "r", stdin);
#define write freopen("output.txt", "w", stdout);
#define endl "\n"
#define IO read write
#define ll long long int
void fileOJ()
{
#ifndef ONLINE_JUDGE
    IO
#endif
}

int main()
{
    FIO;
    fileOJ();
    ll n;
    cin >> n;
    map<ll, ll> mp;
    for (ll i = 1; i <= n - 1; i++)
    {
        ll x;
        cin >> x;
        mp[x] = 1;
    }
    for (ll i = 1; i <= n; i++)
    {
        if (mp[i] == 0)
        {
            cout << i;
            break;
        }
    }
}