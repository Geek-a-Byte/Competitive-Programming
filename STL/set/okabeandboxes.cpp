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
int main()
{
    FIO
    fileOJ();
    set<pair<long long int, string>> s;
    unordered_map<string, long long int> mp;
    int n;
    cin >> n;
    int i = 1;
    while (i <= n)
    {
        int opt;
        cin >> opt;
        if (opt == 1)
        {
            string str;
            cin >> str;
            long long int val;
            cin >> val;
            s.insert({val, str});
            mp[str] = val;
        }
        if (opt == 2)
        {
            string str;
            cin >> str;
            s.erase({mp[str], str});
            long long int val;
            cin >> val;
            s.insert({val, str});
            mp[str] = val;
        }
        if (opt == 3)
        {

            string str;
            cin >> str;

            auto it = s.begin();
            cout << it->second << " " << i << endl;
        }

        i++;
    }
    return 0;
}