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

signed main()
{
    fast
    fileOJ();
    int n,target;
    cin>>n>>target;
    vector<pair<int,int>>a(n);
    int cnt=1;
    for(auto &i:a)
    {
        cin>>i.first;
        i.second=cnt++;
    }
    sort(a.begin(),a.end());
    if(n==3)
    {
        if(a[0].first+a[1].first+a[2].first==target)
        {
            cout<<1<<" "<<2<<" "<<3<<endl;
        }
        else
        {
            cout<<"IMPOSSIBLE"<<endl;
        }
    }
    else{
    for(int i=0;i<n;i++)
    {
        int baki = target-a[i].first;
        int k=n-1;
        for(int j=i+1;j<k;j++)
        {
            while(a[j].first+a[k].first>baki)
            {
                k--;
            }
            if(a[j].first+a[k].first==baki)
            {
                cout<<a[i].second<<" "<<a[j].second<<" "<<a[k].second<<endl;
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    }
}