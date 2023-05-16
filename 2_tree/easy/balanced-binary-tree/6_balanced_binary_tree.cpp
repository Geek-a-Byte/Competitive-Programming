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

class node{
public:
    int data;
    node* left;
    node* right;
};

node* newNode(int value){
    node* nnode= new node();
    nnode->data=value;
    nnode->left=NULL;
    nnode->right=NULL;

    return nnode;
}


// O(n) solution
int maxDepth(node* node)
{
    if (node == NULL)
        return 0;
    else {
        int lDepth = maxDepth(node->left);
        if(lDepth==-1) return -1;
        int rDepth = maxDepth(node->right);
        if(rDepth == -1) return -1;
        if(abs(lDepth-rDepth)>1) return -1;
        return max(lDepth, rDepth)+1;
    }
}

signed main()
{
    fast
    node* root = newNode(1);
 
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    // root->left->right->right = newNode(6);
    
    if(maxDepth(root)==-1) cout<<"Unbalanced tree"<<endl;
    else cout<<"Balanced tree"<<endl;
    return 0;
}