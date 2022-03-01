//time complexity for this algorithm is O(nlogn)

#include <iostream>
#include <map>
using namespace std;

// Data structure to store a Binary Tree node
struct Node
{
    int key;
    Node *left, *right;

    Node(int key)
    {
        this->key = key;
        this->left = this->right = nullptr;
    }
};

// Recursive function to do a pre-order traversal of the tree and fill the map
// Here node has 'dist' horizontal distance from the root of the
// tree and level represent level of the node

void printBottom(Node *node, int dist, int level, auto &map)
{
    // base case: empty tree
    if (node == nullptr)
        return;

    // if current level is more than or equal to maximum level seen so far
    // for the same horizontal distance or horizontal distance is seen for
    // the first time, update the map

    if (level >= map[dist].second || map.find(dist) == map.end())
    {
        // update value and level for current distance
        map[dist] = {node->key, level};
    }

    // recur for left subtree by decreasing horizontal distance and
    // increasing level by 1
    printBottom(node->left, dist - 1, level + 1, map);

    // recur for right subtree by increasing both level and
    // horizontal distance by 1
    printBottom(node->right, dist + 1, level + 1, map);
}

// Function to print the bottom view of given binary tree
void printBottom(Node *root)
{
    // create an empty map where
    // key -> relative horizontal distance of the node from root node and
    // value -> pair containing node's value and its level

    map<int, pair<int, int>> map;

    // do pre-order traversal of the tree and fill the map
    printBottom(root, 0, 0, map);

    // traverse the map and print bottom view
    for (auto it : map)
        cout << it.second.first << " ";
}

int main()
{
    Node *root = nullptr;

    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);

    printBottom(root);

    return 0;
}