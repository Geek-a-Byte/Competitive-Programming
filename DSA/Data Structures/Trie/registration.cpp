#include <bits/stdc++.h>
using namespace std;

struct Trie_Node
{
    map<char, struct Trie_Node *> mp;
    bool endofword;
    int cnt;
    Trie_Node()
    {
        endofword = false;
        cnt = 0;
    }
};

struct Trie_Node root;
int c;

void insert(string str)
{
    struct Trie_Node *curr;
    curr = &root;

    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];

        if (curr->mp.find(ch) == curr->mp.end())
        {
            curr->mp[ch] = new Trie_Node();
        }

        curr = curr->mp[ch];
    }

    curr->endofword = true;
}

bool search(string str)
{
    struct Trie_Node *curr;
    curr = &root;

    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];

        if (curr == NULL)
        {
            return false;
        }
        if (curr->mp.find(ch) == curr->mp.end())
        {
            return false;
        }

        curr = curr->mp[ch];
    }
    if (curr->endofword)
    {
        curr->cnt++;
        c = curr->cnt;
        return true;
    }
    else
    {
        return curr->endofword;
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string str;
        cin >> str;

        if (search(str))
        {
            str = str + to_string(c);
            cout << str << endl;
            insert(str);
        }
        else
        {
            cout << "OK" << endl;
            insert(str);
        }
    }
}
