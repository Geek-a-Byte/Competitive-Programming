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


int isSumProperty(node* node)
{
    int sum = 0;
    // empty tree
    if (node == NULL)
        return 1;
    // if its a leaf node
    if (node->left == NULL && node->right == NULL) 
        return 1;
    else {
        if (node->left)  
        {
            sum += node->left->data;
            cout <<"left value: "<<node->left->data << " ";
        }
        if (node->right)  
        {
            sum += node->right->data;
            cout <<"right value: "<<node->right->data << " ";
        }
        cout<<"sum: "<<sum<<endl;
        return ((node->data == sum) && isSumProperty(node->left) && isSumProperty(node->right));
    }
}

signed main()
{
    fast
    node* root = newNode(10);
    root->left = newNode(8);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
    root->right->right = newNode(2);
 
    // Function call
    if (isSumProperty(root))
        cout << "The given tree satisfies "
             << "the children sum property ";
    else
        cout << "The given tree does not satisfy "
             << "the children sum property ";
 
    return 0;
}