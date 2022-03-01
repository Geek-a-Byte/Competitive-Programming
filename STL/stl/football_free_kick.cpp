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
    TC
    {
        long long int n, k;
        int q;
        cin >> n >> k >> q;
        vector<long long int> v;

        for (long long int i = k + 1; i <= n; i++)
        {
            v.push_back(i);
        }
        cout << "Case " << cn << ":\n";
        for (int i = 0; i < q; i++)
        {
            long long int x, y;
            cin >> x >> y;
            for (auto it = v.begin(); it != v.end(); ++it)
            {
                if (*it == y)
                {
                    v.erase(it);
                    break;
                }
            }
            v.push_back(x);
            sort(v.begin(), v.end());
            long long int sum = 0;
            int c = 0;
            // for (auto it : v)
            // {
            //     cout << it << " ";
            // }
            // cout << endl;
            if (v.size() == 1)
            {
                sum = 1;
                cout << sum << endl;
                continue;
            }
            for (int i = 0; i < v.size() - 1; i++)
            {

                if (c == 0 && ((v[i + 1] - v[i]) == 1))
                {
                    c++;
                    sum += 1;
                }
                else if ((v[i + 1] - v[i]) > 1)
                {
                    if (v.size() == 2 && i + 1 == v.size() - 1)
                        sum++;
                    sum += 1;
                    c = 0;
                }
                //cout << sum << " ";
            }
            //cout << endl;
            cout << sum << endl;
        }
    }
    return 0;
}