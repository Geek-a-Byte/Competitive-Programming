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
    string s;
    cin>>s;
    string left="";
    string right="";
    string odd="";
    map<int,int>mp;
    for(int i=0; i<s.length(); i++)
    {
         mp[s[i]-'A']++;
    }
    
    int odd_cnt=0;
    for(int i=0;i<26;i++)
    {
        if(mp[i]%2)
        {
            odd_cnt++;
            while(mp[i]--){
                odd+=i+'A';
            }
        }
    }
    
    for(int i=0;i<26;i++) {
        if(mp[i]%2==0)
        {
            int half = mp[i] / 2;
            mp[i] -= half;
            while(half--)
            {
                left+= i +'A';
            }
        }
    }
    if(odd_cnt>1)
    {
        cout<<"NO SOLUTION\n";
    }
    else
    {
        for(int i=25;i>=0;i--)
        {
            for(int j=0;j<mp[i];j++)
            {
                right+= i +'A';
            }   
        } 
        cout<<left;
        cout<<odd;         
        cout<<right;
    }

}