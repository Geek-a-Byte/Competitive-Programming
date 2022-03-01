// http://poj.org/problem?id=2001
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
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
void search(char *str, int len)
{
    Node *curr = root;
    for (int i = 0; i < len; i++)
    {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            return;
        curr = curr->next[id];
        printf("%c", str[i]);
        if (curr->num == 1)
        {
            return;
        }
    }
}

int main()
{
    char str[1010][25];
    int n = 0;
    root = new node();

    while (cin >> str[n])
    {
        insert(str[n], strlen(str[n]));
        n++;
    }
    for (int i = 0; i < n; i++)
    {
        cout << str[i] << " ";
        search(str[i], strlen(str[i]));
        cout << endl;
    }

    return 0;
}

/*
comment shoho dile error khay compile error
carbohydrate
cart
carburetor
caramel
caribou
carbonic
cartilage
carbon
carriage
carton
car
carbonate
*/