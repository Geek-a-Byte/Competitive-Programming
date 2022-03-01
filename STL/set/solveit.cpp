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
#define mx 10000000
void fileOJ()
{
#ifndef ONLINE_JUDGE
    IO
#endif
}
using namespace std;
//fast io,set,\n gets accepted, dont use vector,map or unordered map
int main()
{
    FIO
    fileOJ();
    int n, q;
    cin >> n >> q;
    set<int> s;
    for (int i = 0; i < q; i++)
    {
        int op, k, y;
        cin >> op;
        if (op == 1)
        {
            cin >> k;
            s.insert(k);
        }
        else
        {
            cin >> y;
            auto index = s.lower_bound(y);
            if (index != s.end())
            {
                cout << *index << "\n";
            }
            else
            {
                cout << "-1\n";
            }
        }
    }
    return 0;
}