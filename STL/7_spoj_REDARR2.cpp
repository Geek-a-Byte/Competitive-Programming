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

        int n;
        cin >> n;
        priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
        for (int i = 0; i < n; i++)
        {
            long long int x;
            cin >> x;
            pq.push(x);
        }
        // while (!pq.empty())
        // {
        //     cout << pq.top() << " ";
        //     pq.pop();
        // }
        long long int sum = 0;
        while (pq.size() > 1)
        {
            long long int a = pq.top();
            pq.pop();
            long long int b = pq.top();
            pq.pop();
            sum += a + b;

            pq.push(a + b);
        }
        cout << sum << endl;
    }
    return 0;
}