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


vector<int>graph[1000];
bool visited[1000]={false};
void zigzag(int root)
{
    visited[root]=1;
    stack<int>curr;
    stack<int>next;
    
    curr.push(root);
    bool lr = true; //left to right
    while(!curr.empty())
    {
        int top = curr.top();
        curr.pop();
        cout<<top<<" ";
        if(lr)
        {
            for(auto child:graph[top])
            {
                if(!visited[child]){
                    visited[child] = true;
                    next.push(child);
                }
            }
        }
        else
        {
            reverse(graph[top].begin(), graph[top].end());
            for(auto child:graph[top])
            {
                if(!visited[child]){
                    visited[child] = true;
                    next.push(child);
                }
            }

        }
        if(curr.empty())
        {
            lr=!lr;
            swap(curr,next);
        }
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
    
    zigzag(root);
    
}

// input
// 11 10
// 4 9
// 4 2
// 9 3
// 9 5
// 2 7
// 7 8
// 7 10
// 8 11
// 8 12
// 10 13


// output
// 4 2 9 3 5 7 10 8 11 12 13 