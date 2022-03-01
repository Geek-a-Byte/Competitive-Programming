#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
int main()
{
    ll n;
    cin >> n;
    ll res = 1;
    for (ll i = 1; i <= n; i++)
    {
        res = (res % mod * 2 % mod) % mod;
    }
    cout << res % mod << endl;
}