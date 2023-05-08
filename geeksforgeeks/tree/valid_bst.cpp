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

bool isValidBST(node* node,int minVal, int maxVal){
     if(node==NULL)
     {
        return true;
     }
     if(node->data<=minVal or node->data>=maxVal) return false;
     else 
     {
        return (isValidBST(node->left, minVal, node->data) && isValidBST(node->right, node->data, maxVal));
     }
}


signed main()
{
    fast
    node* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(5);
    root->right->left = newNode(7);
    root->left->left = newNode(1);
    root->left->right = newNode(3);

    // Function call
    if (isValidBST(root, LONG_MIN, LONG_MAX))
        printf("Is BST");
    else
        printf("Not a BST");
    return 0;
}