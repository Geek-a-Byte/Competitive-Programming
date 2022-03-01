#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    bool endmark;
    node *next[26 + 1];
} node;

node *createNode()
{
    node *newnode = new node;
    newnode->endmark = false;
    for (int i = 0; i < 26; i++)
    {
        newnode->next[i] = NULL;
    }
    return newnode;
}

node *head = createNode();

void insert(string str, int len)
{
    node *curr = head;
    for (int i = 0; i < len; i++)
    {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
        {
            curr->next[id] = createNode();
        }
        curr = curr->next[id];
    }
    curr->endmark = true;
}

bool search(string str, int len)
{
    node *curr = head;
    for (int i = 0; i < len; i++)
    {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
        {
            return false;
        }
        curr = curr->next[id];
    }
    return curr->endmark;
}
void del(node *curr)
{
    for (int i = 0; i < 26; i++)
    {
        if (curr->next[i])
        {
            del(curr->next[i]);
        }
    }
    delete curr;
}
int main()
{
    //number of words
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        insert(str, str.length());
    }

    //number of queries
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        string str;
        cin >> str;
        if (search(str, str.length()))
        {
            cout << "found\n";
        }
        else
        {
            cout << "not found\n";
        }
    }
    del(head);
    return 0;
}
