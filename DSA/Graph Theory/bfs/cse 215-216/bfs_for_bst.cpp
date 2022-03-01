#include <bits/stdc++.h>
using namespace std;

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
            q.push(temp->left);
            if (temp->left != root)
                temp->left->level = temp->level + 1;
        }
        if (temp->right != NULL)
        {
            q.push(temp->right);
            if (temp->right != root)
                temp->right->level = temp->level + 1;
        }
    }
}
