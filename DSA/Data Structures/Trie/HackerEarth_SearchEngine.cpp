// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/search-engine/
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int weight = 0;
    int endmark;
    node *next[26];
    node()
    {
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
        endmark = 0;
    }
};

typedef struct node Node;
Node *root;

void insert(string s, int wt)
{
    Node *curr = root;
    for (int i = 0; i < s.size(); i++)
    {
        int id = s[i] - 'a';
        if (curr->next[id] == NULL)
            curr->next[id] = new node();

        (curr->next[id])->weight = max(wt, (curr->next[id])->weight);
        curr = curr->next[id];
    }
    curr->endmark = 1;
}

void print_max_weight(string s)
{
    node *curr = root;
    for (int i = 0; i < s.size(); i++)
    {
        int id = s[i] - 'a';
        if (curr == NULL)
        {
            break;
        }
        curr = curr->next[id];
    }
    if (curr == NULL)
    {
        //no valid case found.
        cout << "-1\n";
    }
    else
    {
        //valid case found.
        int ans = 0;
        for (int i = 0; i < 26; i++)
        {
            if (curr->next[i] != NULL)
                ans = max(ans, (curr->next[i])->weight);
        }
        cout << ans << "\n";
    }
}
int main()
{

    int n, q;
    cin >> n >> q;
    root = new node();
    while (n--)
    {
        string s;
        cin >> s;
        int wt;
        cin >> wt;
        insert(s, wt);
    }
    while (q--)
    {
        string s;
        cin >> s;
        print_max_weight(s);
    }
}