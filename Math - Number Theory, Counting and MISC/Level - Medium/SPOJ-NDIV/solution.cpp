#include <bits/stdc++.h>
using namespace std;

#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define read freopen("input.txt", "r", stdin);
#define write freopen("output.txt", "w", stdout);
#define pf printf
#define sf(a) scanf("%d", &a)
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
//#define ll long long int
#define ull unsigned long long int
#define ui unsigned int
#define ld long double
#define pii pair<int, int>
#define mip(a, b) make_pair(a, b)
#define pb push_back
#define ppb pop_back
#define pff push_front
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
#define N 32000
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
#define int long long
void fileOJ()
{
#ifndef ONLINE_JUDGE
    IO
#endif
}
int a[N];
vector<int>p;
// void sieve()
// {
//     for(int i=2;i<=sqrt(N);i++)
//     {
//         if(a[i]==0){
//             for(int j=i+i;j<=N;j+=i)
//             {
//                 if(a[j]==0) a[j]=i;               
//             }
//         }
//     }

// }
void sieve2()
{
    int i,j;
    for(i=4;i<N;i+=2)
        a[i] = 1;
    for(i=3;i<=sqrt(N);i+=2)
    {
        for(j=i*i;j<N;j+=(2*i))
        {
            a[j] = 1;
        }
    }
    for(i=2;i<=N;i++)
    {
        if(a[i]==0)
        {
            p.push_back(i);
            // cout<<i<<endl;
        }
    }
}

void primeFact(int n)
{
    cout<<"1";
    while(n>1)
    {
        int f=a[n];
        while(n%f==0)
        {
            cout<<" x "<<f;
            n/=f;
        }
    }
    cout<<endl;
}
int NOD(int n)
{
    int nod=1;
    while(n>1)
    {
        int cnt=0;
        int f=a[n];
        while(n%f==0)
        {
            n/=f;
            cnt++;
        }
        nod*=(cnt+1);
    }
    return nod;
}

int countDivisor(int n) {
  int divisor = 1;
  int k=0;
  for (int j = p[k]; j * j <= n ; j=p[++k]) {
      int cnt = 1;
      while (n % j == 0) {
        n /= j;
        cnt++;
      }
      divisor *= cnt;
    }
    if(n!=1) divisor*=2;
  return divisor;
}

signed main()
{
    sieve2();
    int A,B,DIV;
    cin>>A>>B>>DIV;
    int cnt=0;
    for(int i=A;i<=B;i++)
    {
        if(countDivisor(i)==DIV) cnt++;
    }
    cout<<cnt;
}