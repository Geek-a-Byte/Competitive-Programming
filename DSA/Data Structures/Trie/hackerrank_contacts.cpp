// https://www.hackerrank.com/challenges/contacts/problem
// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/tries-78733022/description/?fbclid=IwAR3WwlsoidWNCk_ny6zjsHyEgx79SnFNqB1XZATyDZAaPKkRJPVp5Fkqhw4

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int num;
    node *next[26];
    node()
    {
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
        num = 0;
    }
};

typedef struct node Node;
Node *root;

void insert(string str, int len)
{
    Node *curr = root;
    for (int i = 0; i < len; i++)
    {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            curr->next[id] = new node();

        curr = curr->next[id];
        curr->num++;
    }
}
int search(string str, int len)
{
    Node *curr = root;
    //int cnt;
    for (int i = 0; i < len; i++)
    {
        int id = str[i] - 'a';

        if (curr->next[id] == NULL)
        {
            return 0;
        }
        else
            curr = curr->next[id];

        //printf("%c", str[i]);
    }
    return curr->num;
}

int main()
{
    string str, str1;
    int n;
    cin >> n;
    root = new node();

    while (n--)
    {
        cin >> str;
        if (str == "add")
        {
            getchar();
            cin >> str1;
            int l = str1.size();
            insert(str1, l);
        }
        else if (str == "find")
        {
            getchar();
            cin >> str1;
            int l1 = str1.size();
            cout << search(str1, l1) << endl;
        }
    }
}
