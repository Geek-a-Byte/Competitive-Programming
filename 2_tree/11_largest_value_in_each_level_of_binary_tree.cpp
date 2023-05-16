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

vector<int>max_at_each_level;
vector<int>graph[1000];
bool visited[1000]={false};
void bfs(int root)
{
    // cout<<"hello\n";
    visited[root]=1;
    queue<int>q;
    q.push(root);
    int lvl=0;
    while(!q.empty())
    {
        cout<<"at level "<<lvl++<<": "<<endl;
        int nc=q.size(); //no of nodes in the current lvl
        int max_node=INT_MIN;
        while(nc--)
        {
            int parent=q.front();
            q.pop();
            cout<<parent<<" ";
            max_node=max(max_node,parent);
            for(auto child:graph[parent])
            {
                if(!visited[child]) 
                {
                    visited[child]=1;
                    q.push(child);
                }
            }
        }
        cout<<endl;
        max_at_each_level.push_back(max_node);
    }
}


signed main()
{
    fast
    fileOJ();
    int nodes,edges;
    cin>>nodes>>edges;
    int root;
    for(int i=0;i<edges;i++) {
        int u,v;
        cin>>u>>v;
        if(i==0) root=u;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    
    bfs(root);
    // cout<<"max at each level\n";
    // for(auto i:max_at_each_level)
    // {
    //     cout<<i<<" ";
    // }
}

// input
// 6 5
// 4 9
// 4 2
// 9 3
// 9 5
// 2 7


// output
// at level 0: 
// 4 
// at level 1: 
// 9 2 
// at level 2: 
// 3 5 7 
// max at each level
// 4 9 7 