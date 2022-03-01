///https://ideone.com/LNVsxY ->rough tutorial
#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    bool endmark;
    node *next[10 + 1];

} node;

node *createNode()
{
    node *newnode = new node;
    newnode->endmark = false;
    for (int i = 0; i < 10; i++)
    {
        newnode->next[i] = NULL;
    }
    return newnode;
}

node *head = createNode();

void insert(node *head, string str, int len)
{
    node *curr = head;
    for (int i = 0; i < len; i++)
    {
        int id = str[i] - '0';

        if (curr->next[id] == NULL)
        {
            curr->next[id] = createNode();
        }
        curr = curr->next[id];
    }

    curr->endmark = true;
}

bool search(node *head, string str)
{
    node *curr = head;
    for (int i = 0; i < str.length(); i++)
    {
        int id = str[i] - '0';
        // cout << id << " ";
        if (curr->next[id] != NULL && curr->next[id]->endmark == true && i < str.length() - 1)
        {
            return false;
        }
        curr = curr->next[id];
    }
    return true;
}
void del(node *curr)
{
    for (int i = 0; i < 10; i++)
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

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    vector<string> phone_list;
    int n;
    cin >> t;

    while (t--)
    {

        cin >> n;
        for (int i = 0; i < n; i++)
        {
            string str;
            cin >> str;
            phone_list.push_back(str);
            insert(head, str, str.length());
        }

        int flag = 0;
        for (int i = 0; i < phone_list.size(); i++)
        {
            if (search(head, phone_list[i]) == false)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
        head = createNode();
        phone_list.clear();
    }
    del(head);
    return 0;
}