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
    freopen("inputf.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    double h, l; //double nite hobe naile hobe na
    cin >> h >> l;
    double ans = (l * l - h * h) / (2 * h);
    cout << std::fixed<<std::setprecision(13) << ans;
    return 0;
}