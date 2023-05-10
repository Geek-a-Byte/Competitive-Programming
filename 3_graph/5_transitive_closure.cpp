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

#define INF INT_MAX;
// vector<int>graph[1000];
int reachMatrix[1000][1000];

void initMat(int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i==j) reachMatrix[i][j]=1;
            else reachMatrix[i][j]=0;
        }
    }
    
}

void printMat(int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cout<<reachMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

void floydWarshall(int n)
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                reachMatrix[i][j] = ((reachMatrix[i][j]) || (reachMatrix[i][k] && reachMatrix[k][j]));
            }

        }
    }
}

signed main()
{
    fast
    fileOJ();
    
    int nodes,edges;
    cin>>nodes>>edges;
    
    initMat(nodes);

    for(int i=0;i<edges;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        // graph[u].emplace_back(v);
        // graph[v].emplace_back(u);
        reachMatrix[u][v]=w;
    }

    floydWarshall(nodes);
    printMat(nodes);
}

// input
// 4 5
// 1 2 3
// 2 1 2
// 2 3 2
// 3 2 5
// 4 3 8

// output
// 1 1 1 0 
// 1 1 1 0 
// 1 1 1 0 
// 1 1 1 1 
