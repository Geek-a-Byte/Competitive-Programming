#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key, level;
    Node *left, *right, *parent;
};

class BST
{
private:
    Node *root;

public:
    BST()
    {
        root = NULL;
    }

    Node *getRoot() { return root; }

private:
    void insertRoot(int val)
    {
        ///Creates a node in the bst as root
        root = (Node *)malloc(sizeof(Node));
        root->key = val;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
    }

    void insertOther(int val)
    {
        ///Creates a node in the bst which is not root
        Node *temp = root;
        Node *prev = NULL;
        while (temp != NULL)
        {
            prev = temp;
            if (val < temp->key)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        temp = (Node *)malloc(sizeof(Node));
        temp->key = val;
        temp->right = NULL;
        temp->left = NULL;
        temp->parent = prev;
        if (val < prev->key)
        {
            prev->left = temp;
        }
        else
        {
            prev->right = temp;
        }
    }

public:
    void insert(int val)
    {
        ///Creates a node in the bst
        if (root == NULL)
        {
            insertRoot(val);
        }
        else
        {
            insertOther(val);
        }
    }

    Node *findNode(int val)
    {
        ///Returns the reference of a node in the bst that contains the parameter as key
        Node *temp = root;
        while (temp != NULL)
        {
            if (val == temp->key)
            {
                return temp;
            }
            if (val < temp->key)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        return temp;
    }

    Node *findMaximum(Node *node)
    {
        ///Returns the reference of the maximum node in the bst which contains the parameter as root
        Node *temp = node;
        while (temp->right != NULL)
        {
            temp = temp->right;
        }
        return temp;
    }

    Node *findMinimum(Node *node)
    {
        ///Returns the reference of the maximum node in the bst which contains the parameter as root
        Node *temp = node;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp;
    }

    void dfs(Node *node)
    {
        ///Prints the in order traversal of a bst which contains the parameter as root
        if (node == NULL)
        {
            return;
        }
        dfs(node->left);
        cout << node->key << " ";
        dfs(node->right);
    }

private:
    Node *findSuccessor(Node *node)
    {
        ///Returns the reference of the in order successor of the parameter in the bst
        if (node->right != NULL)
        {
            Node *temp = node->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            return temp;
        }
        //case 2 when right subtree is NULL
        Node *p = node->parent;
        while (p != NULL && node == p->right)
        {
            node = p;
            p = p->parent;
        }
        return p;
    }

    void delete0Child(Node *node)
    {
        ///Removes the parameter from the bst if the parameter is a leaf node
        if (node->left == NULL && node->right == NULL)
        {
            if (node == root)
            {
                root = NULL;
                return;
            }
            if (node == node->parent->left)
                node->parent->left = NULL;
            else
                node->parent->right = NULL;
        }
    }

    void delete1Child(Node *node)
    {
        ///Removes the parameter from the bst if the parameter has only one child
        if (node->left == NULL)
        {
            if (node == root)
            {
                root = root->right;
                return;
            }
            if (node->parent->left == node)
            {
                node->parent->left = node->right;
            }
            else
            {
                node->parent->right = node->right;
            }
        }
        if (node->right == NULL)
        {
            if (node == root)
            {
                root = root->left;
                return;
            }
            if (node->parent->left == node)
            {
                node->parent->left = node->left;
            }
            else
            {
                node->parent->right = node->left;
            }
        }
    }

    void delete2Child(Node *node)
    {
        ///Removes the parameter from the bst if the parameter has 2 children
        Node *successor = findSuccessor(node);
        node->key = successor->key;
        if (successor->left == NULL && successor->right == NULL)
        {
            delete0Child(successor);
        }
        if (successor->left == NULL && successor->right != NULL)
        {
            delete1Child(successor);
        }
    }

public:
    bool deleteNode(int val)
    {
        ///Removes a node containing the parameter from the bst
        ///Returns true in case of successful deletion, otherwise returns false
        Node *node = findNode(val);
        if (node == NULL)
        {
            return false;
        }

        if (node->left != NULL && node->right != NULL)
        {
            delete2Child(node);
            return true;
        }
        if ((node->left == NULL && node->right != NULL) || (node->left != NULL && node->right == NULL))
        {
            delete1Child(node);
            return true;
        }
        else
        {
            delete0Child(node);
            return true;
        }
    }

    int height(Node *node)
    {
        ///returns the height of the bst
        ///Must develop a recursive solution
        if (node == NULL)
            return 0;
        int left_subtree_depth = height(node->left);
        int right_subtree_depth = height(node->right);
        if (left_subtree_depth > right_subtree_depth)
        {
            return left_subtree_depth + 1;
        }
        else
        {
            return right_subtree_depth + 1;
        }
    }

    void bfs()
    {
        queue<Node *> q;
        root->level = 0;
        int level = root->level;
        q.push(root);

        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            if (temp->level > level)
            {
                cout << endl;
                level++;
            }
            cout << temp->key << " ";
            if (temp->left != NULL)
            {
                if (temp->left != root)
                    temp->left->level = temp->level + 1;
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                if (temp->right != root)
                    temp->right->level = temp->level + 1;
                q.push(temp->right);
            }
        }
    }
};
