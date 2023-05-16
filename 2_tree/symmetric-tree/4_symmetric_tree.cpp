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


int isSymmetric(node* root1, node* root2){
    
    if(root1==NULL and root2==NULL)
    {
        return 1;
    }
    else if(root1 and root2 and root1->data==root2->data)
    {
        printf("%d ", root1->data);
        printf("%d\n", root2->data);

        int ll_mirror=isSymmetric(root1->left, root2->right);
        int rr_mirror=isSymmetric(root1->right, root2->left);
        return (ll_mirror && rr_mirror);
    }
    return 0;
}

//      1
//    /   \
//   2     2
//  / \   / \
// 3   4 4   3



//    1
//    / \
//   2   2
//    \   \
//    3    3

signed main()
{
    fast
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(4);
    root->right->right = newNode(3);
    
    if (isSymmetric(root,root)) printf("Symmetric");
    else printf("Not symmetric\n");

    node* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(2);
    root2->left->right = newNode(3);
    root2->right->right = newNode(3);
    
    if (isSymmetric(root2,root2)) printf("Symmetric");
    else printf("\nNot symmetric");
    return 0;
}