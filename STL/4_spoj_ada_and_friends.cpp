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
const int INF = 0x3f3f3f3f;
void fileOJ()
{
#ifndef ONLINE_JUDGE
    IO
#endif
}

using namespace std;
unordered_map<string, long long int> mp;
vector<long long int> ans;
int main()
{

    FIO
    fileOJ();
    int t, n;
    while (cin >> t >> n)
    {
        string str;
        long long int exp;
        long long int sum = 0;
        mp.clear();
        ans.clear();
        while (t--)
        {
            cin >> str;
            cin >> exp;
            mp[str] += exp;
        }

        for (auto it : mp)
        {
            ans.push_back(it.second);
        }
        sort(ans.begin(), ans.end(), greater<long long int>());

        for (int i = 0; i < n && i < ans.size(); i++)
        {
            sum += ans[i];
        }
        cout << sum << endl;
    }
    return 0;
}