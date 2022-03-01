#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int key;
    Node *next;
} Node;
//first node is the head node
//last node is the tail node
// Head pointer always points to first element of the linked list
Node *head = NULL;

Node *createNode(int data)
{
    Node *new_node = new Node;
    new_node->key = data;
    new_node->next = NULL;
    return new_node;
}
int getSize()
{
    Node *temp = head;
    int count = 0;

    //1.traverse to the end of the list

    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    //2.point the last node to new node

    return count;
}

void printList()
{
    Node *temp;
    temp = head;
    while (temp != NULL)
    {
        cout << temp->key << " ";
        temp = temp->next;
    }
    cout << endl;
}
void freeTheList()
{
    Node *temp = head;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
void SearchKey(int val)
{
    Node *temp = head;
    int pos = 1;
    while (temp != NULL)
    {
        if (temp->key == val)
            break;
        temp = temp->next;
        pos++;
    }
    if (temp == NULL)
    {
        cout << "not found" << endl;
    }
    else
    {
        cout << "found the value " << val << " at " << pos << endl;
    }
}
int SearchAt(int pos)
{
    Node *temp = head;
    if (temp != NULL)
    {
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }
    }
    else
    {
        cout << "The list is empty" << endl;
    }

    return temp->key;
}
int main()
{
    int n;
    cout << "enter the size of the linked list: \n";
    cin >> n;
    int data;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        Node *new_node = createNode(data);

        if (head == NULL)
        {
            head = new_node;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }
    cout << "enter\n0 -> break\n1 -> SearchKey\n2 -> SearchAt\n3 -> printlist\n";
    int choice;
    while (1)
    {
        cin >> choice;

        if (choice == 1)
        {
            int key;
            cout << "enter the key you are searching for\n";
            cin >> key;

            SearchKey(key);
        }
        else if (choice == 2)
        {
            int pos;
            cout << "enter the position you want to search value of\n";
            cin >> pos;
            int size = getSize();
            if (pos == 0 || pos >= size + 1)
            {
                cout << "invalid position\n";
            }
            else
            {
                int res = SearchAt(pos);
                cout << "The element fount at " << pos << " is " << res << endl;
            }
        }

        else if (choice == 0)
        {
            break;
        }
        else if (choice == 3)
        {
            printList();
        }
        else
        {
            cout << "invalid choice" << endl;
        }
    }
    freeTheList();
}