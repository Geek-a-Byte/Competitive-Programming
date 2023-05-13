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

vector<int>graph[1000]; // vector er array
bool visited[1000];
map<int,int>mp;
void dfs(int node, int par, int lvl, int& max_lvl, int& max_node)
{
    mp[node]=par;
    visited[node] = true;
    if (lvl > max_lvl) {
        max_node = node;
        max_lvl = lvl;
    }
    // trace(node, lvl);
    for (int child : graph[node]) {
        if (!visited[child]) {
            dfs(child, node, lvl + 1, max_lvl, max_node);
        }
    }
}

signed main()
{
    fast;
    fileOJ();
    int t;
    cin>>t;
    
    while(t--) {
         int n, m; cin >> n >> m; // nodes, edges
         int max_node = -1;
         int max_lvl = -1;  
         
         mp.clear();
         for(int i=0; i<n+1; i++)
         {
            graph[i].clear();
            visited[i]=false;
         }
         int a,b;
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b; 
            graph[a].emplace_back(b); 
            graph[b].emplace_back(a);
        }

        dfs(a, -1, 0, max_lvl, max_node); 

        int root = max_node;
        int second_par=mp[root];
        int central_par=mp[second_par];
        int x=graph[central_par].size();
        int y = (n-1)/x;
        cout<<x<<" "<<y-1<<endl; 
    }
    
   
  
    // cout << max_lvl << endll;
}