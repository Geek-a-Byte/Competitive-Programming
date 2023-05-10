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

int identicalTrees(node* tree1, node* tree2)
{
   if(tree1==NULL and tree2==NULL)
   {
      return 1;
   }
   else if(tree1->data==tree2->data)
   {
      int left_subtrees_same = identicalTrees(tree1->left, tree2->left);
      int right_subtrees_same = identicalTrees(tree1->right, tree2->right);
      return (left_subtrees_same && right_subtrees_same);
   }
   return 0;
}

signed main()
{
    fast
    node* root1 = newNode(1);
 
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);


    node* root2 = newNode(1);
 
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);

    node* root3 = newNode(1);
 
    root3->left = newNode(2);
    root3->right = newNode(4);
    root3->left->left = newNode(5);
    root3->left->right = newNode(6);

    // Function call
    if (identicalTrees(root2, root3))
        printf("Both trees are identical.");
    else
        printf("Trees are not identical.");
    return 0;
}