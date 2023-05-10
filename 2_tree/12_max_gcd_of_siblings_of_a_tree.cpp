#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define read freopen("input.txt", "r", stdin);
#define write freopen("output.txt", "w", stdout);
#define IO read write
#define TC int tc; cin >> tc; for (int cn = 1; cn <= tc; ++cn)
#define rep(i,n) for(int i = 0; i < n; i++)

#define ll long long int
#define ull unsigned long long int
#define ui unsigned int
#define ld long double
#define ff first
#define ss second

#define pii pair<int, int>
#define stlloop(x) for (__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define CLR(p) memset(p, 0, sizeof(p))
#define sp(x) std::cout << std::fixed << std::setprecision(x)
#define sort(x) sort(x.begin(), x.end())

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

// Time Complexity: O(nlogn), as sort() takes O(nlogn) time.
// Auxiliary Space: O(1)

int max_gcd(vector<pair<int,int>>&v)
{
    if(v.size()==0 or v.size()==0)
    {
        return 0;
    }

    sort(v);

    pii a=v[0];
    int ans=INT_MIN;
    for(int i=1; i<v.size(); i++)
    {
        pii b=v[i];
        if(b.ff==a.ff)
        {
            ans=max(ans,gcd(a.ss,b.ss));
        }
        a=b;
    }
    return ans;
}

signed main()
{
    fast
    fileOJ();
    vector<pair<int, int> > v;
    v.push_back(make_pair(5, 4));
    v.push_back(make_pair(5, 8));
    v.push_back(make_pair(4, 6));
    v.push_back(make_pair(4, 9));
    v.push_back(make_pair(8, 10));
    v.push_back(make_pair(10, 20));
    v.push_back(make_pair(10, 30));
    
    cout<<max_gcd(v);
}
