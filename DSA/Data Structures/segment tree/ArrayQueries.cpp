#include "bits/stdc++.h"
#define ll long long
#define ull unsigned long long
#define PI acos(-1)
#define rep(i,k, n) for (int i = k; i < n; i++)
#define repj(i,k, n) for (int i = k; i <= n; i++)
#define MP(x, y) make_pair(x, y)
#define PB(x) push_back(x)
#define All(p) p.begin(), p.end()
#define CLR(p) memset(p, 0, sizeof(p))
#define ff first
#define ss second
#define sf scanf
#define pf printf
#define PII pair<int, int>
#define mx 100001
using namespace std;
int arr[mx];
int tree[mx*3];

void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=arr[b];
        
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=min(tree[left],tree[right]);
    //cout<<tree[node]<<" ";

}

int query(int node,int b,int e,int i,int j)
{
    if(b>=i && e<=j)
    {
        return tree[node];
    }
    int m1=mx;
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    if(i<=mid){
    m1=min(m1,query(left,b,mid,i,j));
    }
    if(j>mid){
    m1=min(m1,query(right,mid+1,e,i,j));
    }
    return m1;
}

int main()
{
    //for faster i/o
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //for file input output
    freopen("inputf.in", "r", stdin);
    freopen("outputf.in", "w", stdout);
    int t;
    cin>>t;
    
    repj(i,1,t)
    {
        int n,q;
        cin>>n>>q;
        arr[0]=0;
        repj(j,1,n)
        {
           cin>>arr[j];
        }
        init(1,1,n);
        
         cout<<"Case "<<i<<":\n";
        repj(j,1,q){
        int a,b;
        cin>>a>>b;
        cout<<query(1,1,n,a,b)<<"\n";
        
    }
     
    }


        