#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define read freopen("../input.txt", "r", stdin);
#define write freopen("../output.txt", "w", stdout);
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

vector<int>graph[1000];
bool visited[1000]={false};
void dfs(int parent)
{
    cout<<parent<<" ";
    visited[parent]=1;
    for(auto child: graph[parent])
    {
        if(!visited[child])
        {
            visited[child]=1;
            dfs(child);
        }
    }
}

signed main()
{
    fast
    fileOJ();
    int nodes,edges;
    cin>>nodes>>edges;
    for(int i=0;i<edges;i++) {
        int u,v;
        cin>>u>>v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    cout<<"dfs traversal\n";
    for(int i=1;i<=nodes;i++){
        if(!visited[i]) dfs(i);
    }
}

// input
// 5 4
// 1 2
// 1 5
// 2 3 
// 2 4

// output
// dfs traversal
// 1 2 3 4 5 