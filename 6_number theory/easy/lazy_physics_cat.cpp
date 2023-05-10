#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define PI acos(-1)
#define rep(i, k, n) for (int i = k; i < n; i++)
#define MP(x, y) make_pair(x, y)
#define PB(x) push_back(x)
#define All(p) p.begin(), p.end()
#define CLR(p) memset(p, 0, sizeof(p))
#define ff first
#define ss second
#define sf scanf
#define pf printf
#define PII pair<int, int>

using namespace std;

int main()
{
    //for faster i/o
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //for file input output
    //freopen("input.txt", "r", stdin);
    //freopen("outputf.in", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int l, a;
        cin >> l >> a;
        double rad = (PI * a) / 180;
        double area1 = (l * l * rad) / 2;
        double area2 = (0.5 * l * l) * sin(rad);
        std::cout << std::fixed;
        std::cout << std::setprecision(6) << area1 - area2 << endl;
    }
    return 0;
}