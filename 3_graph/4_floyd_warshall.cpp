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

#define INF INT_MAX
// vector<int>graph[1000];
int reachMatrix[1000][1000];
int nextNode[1000][1000];

// http://www.shafaetsplanet.com/?p=1927

void initMat(int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i==j) reachMatrix[i][j]=0;
            else reachMatrix[i][j]=INF;

            
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
// ৩টা নেস্টেড লুপ ঘুরছে নোড স‍ংখ‍্যার উপর, টাইম কমপ্লেক্সিটি O(n^3)। ২ডি ম‍্যাট্রিক্স ব‍্যবহার করায় স্পেস কমপ্লেক্সিটি O(n^2)।
void floydWarshall(int n)
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(reachMatrix[i][j] > reachMatrix[i][k] + reachMatrix[k][j]){
                    reachMatrix[i][j] = reachMatrix[i][k] + reachMatrix[k][j];
                    nextNode[i][j]=nextNode[i][k];
                } 
            }

        }
    }
}

vector<int> findPath(int i, int j)
{
    vector<int>path={i};

    while(i!=j)
    {
        i=nextNode[i][j];
        path.push_back(i);
    }
    return path;
}

void printPath(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(reachMatrix[i][j]!=INF){
                vector<int>path = findPath(i,j);
                cout<<"the shortest path between "<<i<<" to "<<j<<" : ";
                for(auto node:path)
                {
                    cout<<node<<" ";
                }
                cout<<endl;
            }
            else
            {
                cout<<"There is no path between "<<i<<" to "<<j<<endl;
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
        nextNode[u][v]=v;
    }

    floydWarshall(nodes);
    printMat(nodes);
    printPath(nodes);
}

// input
// 4 5
// 1 2 3
// 2 1 2
// 2 3 2
// 3 2 5
// 4 3 8

// output
// 0 3 5 2147483647 
// 2 0 2 2147483647 
// 7 5 0 2147483647 
// 15 13 8 0 
// the shortest path between 1 to 1 : 1 
// the shortest path between 1 to 2 : 1 2 
// the shortest path between 1 to 3 : 1 2 3 
// There is no path between 1 to 4
// the shortest path between 2 to 1 : 2 1 
// the shortest path between 2 to 2 : 2 
// the shortest path between 2 to 3 : 2 3 
// There is no path between 2 to 4
// the shortest path between 3 to 1 : 3 2 1 
// the shortest path between 3 to 2 : 3 2 
// the shortest path between 3 to 3 : 3 
// There is no path between 3 to 4
// the shortest path between 4 to 1 : 4 3 2 1 
// the shortest path between 4 to 2 : 4 3 2 
// the shortest path between 4 to 3 : 4 3 
// the shortest path between 4 to 4 : 4 
