// map 

#include <bits/stdc++.h>
using namespace std;

struct Trie_Node
{
    map<char, struct Trie_Node *> mp;
    bool endofword = false;
};

struct Trie_Node root;

void insertWord(char str[]);
struct Trie_Node *Get_newNode();
bool searchWord(char str[]);
void deleteWord(char str[], int index, struct Trie_Node *&cur, int len);

int main()
{
    char str[45];
    int c = 0;

    while (c != 4)
    {
        system("cls");
        cout << "Press 1 to Add an Word to the Trie Tree : \n\n";
        cout << "Press 2 to Search an Word in the Trie Tree : \n\n";
        cout << "Press 3 to Delete an Word from the Trie Tree : \n\n";
        cin >> c;

        switch (c)
        {
        case 1:
        {
            system("cls");
            cout << "Enter the Word : ";
            cin >> str;
            insertWord(str);
            cout << "The Word has been Inserted \n";
            cout << "Please Press 1 to Back to the Menu or 4 to Exit\n";
            cin >> c;
            break;
        }

        case 2:
        {
            system("cls");
            cout << "Enter the Word : ";
            cin >> str;
            if (searchWord(str))
            {
                cout << "Word is Found \n";
                cout << "Please Press 1 to Back to the Menu or 4 to Exit";
                cin >> c;
            }
            else
            {
                cout << "Word is Not Found \n";
                cout << "Please Press 1 to Back to the Menu or 4 to Exit\n";
                cin >> c;
            }
            break;
        }

        case 3:
        {
            system("cls");
            cout << "Enter the Word : ";
            cin >> str;
            if (!searchWord(str))
            {
                cout << "Word is not Found \n";
            }
            else
            {
                struct Trie_Node *temp;
                temp = &root;
                deleteWord(str, 0, temp, strlen(str));
                cout << "The Word has been deleted \n";
            }
            cout << "Please Press 1 to Back to the Menu or 4 to Exit";
            cin >> c;
            break;
        }

        default:
            break;
        }
    }
}

//Creating New Node
struct Trie_Node *Get_newNode()
{
    struct Trie_Node *newNode = new struct Trie_Node;
    return newNode;
}

//Inserting on The Trie Tree
void insertWord(char str[])
{
    struct Trie_Node *temp;
    temp = &root;

    for (int i = 0; i < strlen(str); i++)
    {
        char ch = str[i];

        if (temp->mp.find(ch) == temp->mp.end())
        {
            temp->mp[ch] = Get_newNode();
        }

        temp = temp->mp[ch];
    }

    temp->endofword = true;
}

//Searching a Word in the Trie Tree
bool searchWord(char str[])
{
    struct Trie_Node *temp;
    temp = &root;

    for (int i = 0; i < strlen(str); i++)
    {
        char ch = str[i];
        if (temp->mp.find(ch) == temp->mp.end())
        {
            return false;
        }
        temp = temp->mp[ch];
    }

    return temp->endofword;
}

//Delete Node
void deleteWord(char str[], int index, struct Trie_Node *&cur, int len)
{
    if (len == index)
    {
        if (cur->mp.empty())
        {
            delete cur;
            cur = nullptr;
        }
        else
        {
            cur->endofword = false;
        }
    }
    else
    {
        int c = index;
        deleteWord(str, ++c, cur->mp[str[index]], len);
        if (cur->mp[str[index]] == NULL)
        {
            cur->mp.erase(str[index]);
            if (cur->mp.empty() && !cur->endofword)
            {
                delete cur;
                cur = nullptr;
            }
        }
        return;
    }
}
