#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define read freopen("input.txt", "r", stdin);
#define write freopen("output.txt", "w", stdout);
#define IO read write
#define TC int tc; cin >> tc; for (int cn = 1; cn <= tc; ++cn)
#define rep(i,n) for(int i = 0; i < n; i++)

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


node* sortedArrtoBST(int arr[], int s, int e)
{
      if(s>e)
      {
        return NULL;
      }
      int mid=(s+e)/2;
      node* root = newNode(arr[mid]);
      root->left = sortedArrtoBST(arr, s, mid-1);
      root->right = sortedArrtoBST(arr, mid+1, e);
      return root;
}

/* Helper function to print
preorder traversal.*/
void preOrder(node* node)
{
    if (node == NULL)
        return;
 
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

/* Helper function to print
preorder traversal.*/
void postOrder(node* node)
{
    if (node == NULL)
        return;
 
    postOrder(node->left);
    postOrder(node->right);
    cout << node->data << " ";
}

/* Helper function to print
preorder traversal.*/
void inOrder(node* node)
{
    if (node == NULL)
        return;
 
    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}

signed main()
{
    fast
    int arr[]={10,20,30,40,50};
    node* root = sortedArrtoBST(arr,0,4);
    cout<<"\nPreOrder Traversal\n";
    preOrder(root);
    cout<<"\nPostOrder Traversal\n";
    postOrder(root);
    cout<<"\nInOrder Traversal\n";
    inOrder(root);
}