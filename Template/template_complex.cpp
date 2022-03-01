#include <bits/stdc++.h>
using namespace std;

#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define read freopen("input.txt", "r", stdin);
#define write freopen("output.txt", "w", stdout);
#define pf printf
#define sf(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define sff(a, b) scanf("%d %d", &a, &b)
#define sffl(a, b) scanf("%lld %lld", &a, &b)
#define sfff(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define sfffl(a, b, c) scanf("%lld %lld %lld", &a, &b, &c)
#define scd(a) scanf("%lf", &a)
#define scd2(a, b) scanf("%lf %lf", &a, &b)
#define scd3(a, b, c) scanf("%lf %lf %lf", &a, &b, &c)
#define endl "\n"
#define D(x) cout << '>' << #x << ':' << x << endl
#define DD(x, y) cout << '>' << #x << ':' << x << ' ' << #y << ':' << y << endl
#define DDD(x, y, z) cout << '>' << #x << ':' << x << ' ' << #y << ':' << y << ' ' << #z << ':' << z << endl
#define TC     \
    int tc;    \
    cin >> tc; \
    for (int cn = 1; cn <= tc; ++cn)
#define sp(x) std::cout << std::fixed << std::setprecision(x)
#define ll long long int
#define ull unsigned long long int
#define ui unsigned int
#define ld long double
#define pii pair<int, int>
#define mip(a, b) make_pair(a, b)
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define forrev(i, n) for (int i = n - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = a; i <= b; i++)
#define forba(i, b, a) for (int i = b; i >= a; i--)
#define stlloop(x) for (__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define ALL(p) p.begin(), p.end()
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(a, b) memset(a, b, sizeof(a))
#define IO read write
#define PI acos(-1)
#define ff first
#define ss second
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a) * ((b) / gcd(a, b)))
#define max3(a, b, c) max(a, b) > max(b, c) ? max(a, b) : max(b, c)
#define min3(a, b, c) min(a, b) < min(b, c) ? min(a, b) : min(b, c)
#define case1(z) cout << "Case " << z << ": "
#define case2(z) printf("Case %d: ", z)
#define mx 10000000
const int INF = 0x3f3f3f3f;
const int big = INT_MAX;
const int sml = INT_MIN;
const int mod = 100000007;
const int INT5 = 100005;
const int INT6 = 1000005;
const int INT7 = 10000005;
const int INT8 = 100000005;
const long long INT9 = 1000000005;
const long long INT12 = 1000000000005;
void fileOJ()
{
#ifndef ONLINE_JUDGE
    IO
#endif
}

int main()
{
    FIO;
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
#endif
    fileOJ();
    TC
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
        }
    }
#ifndef ONLINE_JUDGE
    printf("\nRun Time -> %.8fs", (double)(clock() - tStart) / CLOCKS_PER_SEC);
#endif
    return 0;
}