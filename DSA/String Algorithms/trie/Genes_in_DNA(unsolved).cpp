#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define PI acos(-1)
#define rep(i, k, n) for (int i = k; i < n; i++)
#define MP(x, y) make_pair(x, y)
#define PB(x) push_back(x)
#define All(p) p.begin(), p.end()
#define CLR(p) memset(p, 0, sizeof(p))
#define ff first
#define ss second
#define sf scanf
#define pf printf
#define PII pair<int, int>

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

void insert(node *head, string str, int len)
{
    node *curr = head;
    for (int i = 0; i < len; i++)
    {
        int id = str[i] - 'A';
        if (curr->next[id] == NULL)
        {
            curr->next[id] = createNode();
        }
        curr = curr->next[id];
    }
    curr->endmark = true;
}

int search(node *head, string str)
{
    int c = 0;
    node *curr = head;
    for (int i = 0; i < str.length(); i++)
    {
        int id = str[i] - 'A';
        // cout << id << " ";
        if (curr->next[id] != NULL && curr->next[id]->endmark == true && i < str.length() - 1)
        {
            c++;
        }
        curr = curr->next[id];
    }
    return c;
}
int main()
{
    //for faster i/o
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //for file input output
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        node *head = createNode();
        /* code */
        int n;
        cin >> n;
        vector<string> v;
        vector<int> counts;
        for (int i = 0; i < n; i++)
        {
            string str;
            cin >> str;
            v.push_back(str);
            counts.push_back(str.size());
            insert(head, str, str.size());
        }

        for (int i = 0; i < n; i++)
        {
            int c1 = search(head, v[i]);
            counts.push_back(c1);
        }
    }

    return 0;
}