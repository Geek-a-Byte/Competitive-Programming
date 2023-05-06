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
map<string,int>mp;
map<int,string>mp2;
signed main()
{
    fast
    fileOJ();
    int t;
    cin>>t;
    int cn=1;
    string line;
    getline(cin,line);
    while(t--){
        mp.clear();
        mp2.clear();
        getline(cin,line);
        // cout<<line<<endl;
        stringstream ss(line);
        string word;

        while (ss >> word) {
            // cout << word << std::endl;
            mp[word]++;
        }

        priority_queue<pair<int,string>>pq;

        for(auto i:mp)
        {
            pq.push({i.second,i.first});
        }        

        cout<<"Year-"<<cn++<<endl;
        while(pq.size()!=0)
        {
            cout<<pq.top().second<<" "<<pq.top().first<<endl;
            pq.pop();
        }
    }
}