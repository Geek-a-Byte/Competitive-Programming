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
    vector<ll> v;
    ll n;
    cin >> n;
    ll mov = 0;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        v.push_back(x);
        if (i > 0 and v[i] < v[i - 1])
        {
            mov += v[i - 1] - v[i];
            v[i] += v[i - 1] - v[i];
        }
    }
    cout << mov << endl;
}