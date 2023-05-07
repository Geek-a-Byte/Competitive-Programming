#include"bits/stdc++.h"
using namespace std;

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;

struct _ { ios_base::Init i; _() { cin.sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10); } } ___;
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
    cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << "  ";
    __f(comma + 1, args...);
}

#define ll long long
#define pii pair<int,int>
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ff first
#define ss second
#define endll '\n'
#define rep(i,n) for(int i=0;i++<n;)
#define scl(i) scanf("%lld",&i)
#define int long long int
#define all(n) n.begin(),n.end()
#define mem(n,i) memset(n,i,sizeof n)
#define em(a) emplace_back(a)
#define pb(a) push_back(a)
#define srep(it,vv) for(auto &it : vv)
#define prep(it,vv) for(auto it : vv)
#define b_s(a,b) binary_search(a.begin(),a.end(),b)
#define l_b(a,b) lower_bound(a.begin(),a.end(),b)
#define u_b(a,b) upper_bound(a.begin(),a.end(),b)
#define uniq(x) sort(x.begin(),x.end());x.erase(unique(x.begin(),x.end()),x.end())
//vector<vector<int>>arr(n + 5, vector<int>(m + 5,0));

typedef vector<int> vii;
typedef vector<pii> vpp;
typedef vector<string> vss;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r) {
    return uniform_int_distribution<int>(l, r) (rng);
}

int max_node = -1;
int max_lvl = -1;

vector<int>graph[1000]; // vector er array
bool visited[1000];

void dfs(int node, int par, int lvl)
{
    visited[node] = true;
    if (lvl > max_lvl) {
        max_node = node;
        max_lvl = lvl;
    }
    trace(node, lvl);
    for (int child : graph[node]) {
        if (!visited[child]) {
            dfs(child, node, lvl + 1);
        }
    }
}

signed main()
{
    int n, m; cin >> n >> m; // nodes, edges 
    for (int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b; 
        graph[a].em(b); 
        graph[b].em(a);
    }

    dfs(1, -1, 0); // curr node, parent, curr level
    // trace(max_lvl, max_node);

    int root = max_node;

    max_lvl = -1;
    for(int i = 0; i <1000;i++)
    {
        visited[i]=false;
    }

    dfs(root, -1, 0);
    trace(max_lvl, max_node);
    cout<<"The number of the nodes in the longest path of the tree i.e diameter: "<<max_node+1<<endl;
    // cout << max_lvl << endll;
}