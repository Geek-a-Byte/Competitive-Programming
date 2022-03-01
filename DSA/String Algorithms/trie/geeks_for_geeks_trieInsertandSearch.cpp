// https://practice.geeksforgeeks.org/problems/trie-insert-and-search/0#
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

void insert(char *str, int len)
{
    Node *curr = root;
    for (int i = 0; i < len; i++)
    {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
    }
    curr->endmark = true;
}
bool search(string str, int len)
{
    Node *curr = root;
    for (int i = 0; i < len; i++)
    {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            return false;
        curr = curr->next[id];
    }
    return curr->endmark;
}

int main()
{
    //puts("ENTER NUMBER OF WORDS");
    int t;
    cin >> t;
    while (t--)
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
        //puts("ENTER NUMBER OF QUERY");
        string str;
        cin >> str;
        if (search(str, str.size()))
            cout << "1" << endl;
        else
            cout << "0" << endl;
    }
}
