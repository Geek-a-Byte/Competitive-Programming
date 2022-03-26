#include <bits/stdc++.h>
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define TC     \
    int tc;    \
    cin >> tc; \
    for (int cn = 1; cn <= tc; ++cn)
#define read freopen("input.txt", "r", stdin);
#define write freopen("output.txt", "w", stdout);
#define sp(x) std::cout << std::fixed << std : : setprecision(x);
#define IO read write
#define PI acos(-1)
#define MP(x, y) make_pair(x, y)
#define CLR(p) memset(p, 0, sizeof(p))
#define ff first
#define ss second
#define PII pair<int, int>
#define N 10000007
#define ll long long
void fileOJ()
{
#ifndef ONLINE_JUDGE
    IO
#endif
}
 
using namespace std;
ll p[N];
bool a[N];
ll sz;
void sieve()
{
    ll i, j;
    for (i = 4; i < N; i += 2)
        a[i] = 1;
    for (i = 3; i <= sqrt(N); i += 2)
    {
        for (j = i * i; j < N; j += (2 * i))
        {
            a[j] = 1;
        }
    }
    j = 0;
    for (i = 2; i < N; i++)
    {
        if (a[i] == 0)
        {
            p[j] = i;
            //cout<<i<<endl;
            j++;
        }
    }
    sz = j;
    // for (int i = 0; i < sz; i++)
    // {
    //     cout << p[i] << " " << endl;
    // }
}

int main()
{
    FIO
    //fileOJ();
    sieve();
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        int div = i;
        int loop = 0;
        for (int j = 0; j <= n; j++)
        {
            if (div % p[j] == 0)
            {
                div = div / p[j];
                loop++;
            }
        }
        if (loop == 2)
            cnt++;
    }
    cout << cnt << endl;
 
    return 0;
}