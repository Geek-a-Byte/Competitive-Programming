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
    int t;
    cin>>t;
    string a,b;
    getline(cin,a);
    while(t--) {
        /* code */
        // string a,b;
        getline(cin,a);
        getline(cin,b);
        for(int i=0;i<a.length();i++)
        {
            a[i]=tolower(a[i]);
        }
        string bo="";

        for(int i=2;i<b.length()-2;i++)
        {
            bo+=tolower(b[i]);
        }
        // cout<<bo<<endl;
        int pos = a.find(bo);
        int f=0;
        if (pos>=0 and pos<=a.length()-1) {
            if(pos+bo.length()-1==a.length()-1)
            {
                f=1;
            }
            if(pos==0)
            { 
               f=1;
            }
            if(pos>0 and a[pos-1]==' ')
            {

                f=1;
            }
            if(pos!=a.length()-1 and a[pos+bo.length()]==' ')
            {
                f=1;
            }
        }
        else
        {
            f=1;
        }
        if(f==1)
        {
            cout<<"no\n";
        }
        else
        {
            cout<<"yes\n";
        }
    }
    
}