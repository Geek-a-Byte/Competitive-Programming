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

void insert(char *str, int len)
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
int search(char *str, int len)
{
    Node *curr = root;
    for (int i = 0; i < len - 1; i++)
    {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            return -1;
        curr = curr->next[id];
        // printf("%c", str[i]);
    }
    return curr->num;
}

int main()
{
    char str[12];
    int n;
    cin >> n;
    root = new node();

    while (n--)
    {
        cin >> str;
        insert(str, strlen(str));
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> str;
        cout << str << " ";
        if (search(str, strlen(str)) == 0)
        {
            cout << "-1";
        }
        else
        {
            cout << search(str, strlen(str));
        }

        cout << endl;
    }

    return 0;
}

/*
10

apple

banana


orange

applet

banana

oriental

orange

oriental

applet

bangalore

8

ban

bang

app

or

oriental

apple

hobbits

oranges
*/
