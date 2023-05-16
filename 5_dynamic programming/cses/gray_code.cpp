#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define read freopen("input.txt", "r", stdin);
#define write freopen("output.txt", "w", stdout);
#define IO read write
#define TC int tc; cin >> tc; for (int cn = 1; cn <= tc; ++cn)
#define rep(i,n) for(int i = 0; i < n; i++)

#define int long long
#define ll long long int
#define ull unsigned long long int
#define ui unsigned int
#define ld long double

#define pii pair<int, int>
#define stlloop(x) for (__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define CLR(p) memset(p, 0, sizeof(p))
#define sp(x) std::cout << std::fixed << std::setprecision(x)

#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*(b))/gcd(a, b)

#define PI acos(-1)
#define N 10000000
const int INF = 0x3f3f3f3f;
const int mod = 100000007;


void fileOJ()
{
#ifndef ONLINE_JUDGE
    IO
#endif
}

vector<string> solve(int n)
{
    vector<string>res;
    if(n==1)
    {
        res.push_back("0");
        res.push_back("1");
        return res;
    }
    
    vector<string>prev=solve(n-1);
    int s=prev.size();
   
    for(int i=0; i<s; i++)
    {
        string w="0";
        res.push_back(w+prev[i]);
    }
    for(int i=s-1;i>=0;i--)
    {
        string w="1";
        res.push_back(w+prev[i]);
    }
    
    return res;
    
}
signed main()
{
    fast
    fileOJ();
    int n;
    cin>>n;
    vector<string>ans=solve(n);
    for(auto i:ans)
    {
       cout<<i<<endl;
    }
}