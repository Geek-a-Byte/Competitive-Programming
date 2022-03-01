// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/cost-of-data-11/
#include <bits/stdc++.h>
using namespace std;

struct node
{
    bool endmark;
    node *next[26];
    node()
    {
        endmark = false;
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
    }
};

typedef struct node Node;
Node *root;
int total_node;
void insert(char *str, int len)
{
    Node *curr = root;
    for (int i = 0; i < len; i++)
    {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
        {
            curr->next[id] = new node();
            total_node++;
        }
        curr = curr->next[id];
    }
    curr->endmark = true;
}

int main()
{

    root = new node();
    int num_word;
    cin >> num_word;
    for (int i = 1; i <= num_word; i++)
    {
        char str[50];
        scanf("%s", str);
        insert(str, strlen(str));
    }
    cout << total_node + 1;

    return 0;
}