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
void DeleteBegin()
{
    Node *temp = head;
    head = head->next;
    free(temp);
    cout << "Successfully deleted the first node" << endl;
}

void DeleteEnd()
{
    Node *prev, *curr;
    curr = head;
    while (curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;
    }
    free(curr);
    prev->next = NULL;
    cout << "Successfully deleted the last node" << endl;
}

void DeleteAt(int pos)
{
    if (pos == 1)
    {
        DeleteBegin();
    }
    else if (head == NULL)
    {
        cout << "the list is empty" << endl;
        return;
    }
    else
    {

        Node *temp = head;
        Node *prev = head;
        for (int i = 1; i < pos; i++)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        cout << "successfully deleted " << temp->key << " at pos " << pos << endl;
        free(temp);
    }
}
void DeleteKey(int val)
{
    Node *temp = head;
    Node *prev = head;

    int pos = 1;
    while (temp != NULL)
    {
        if (temp->key == val)
            break;
        prev = temp;
        temp = temp->next;
        pos++;
    }
    if (temp == NULL)
    {
        cout << "couldn't find the value\n";
        return;
    }
    if (pos == 1)
    {
        DeleteBegin();
    }
    else
    {
        prev->next = temp->next;
        free(temp);
        cout << "Successfully deleted " << val << endl;
    }
}

void printList()
{
    if (head == NULL)
    {
        cout << "the list is empty\n";
    }
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
    cout << "enter\n0 -> break\n1 -> DeleteBegin\n2 -> DeleteAt\n3 -> DeleteEnd\n4 -> DeleteKey\n5 -> printlist\n";
    int choice;
    while (1)
    {
        cin >> choice;

        if (choice == 1)
        {
            DeleteBegin();
        }
        else if (choice == 2)
        {
            int pos;
            cout << "enter the position you want to delete value of\n";
            cin >> pos;
            int size = getSize();
            if (pos == 0 || pos >= size + 1)
            {
                cout << "invalid position\n";
            }
            else
            {
                DeleteAt(pos);
            }
        }
        else if (choice == 3)
        {
            DeleteEnd();
        }

        else if (choice == 4)
        {
            int key;
            cout << "enter the key you are searching to delete for\n";
            cin >> key;
            DeleteKey(key);
        }
        else if (choice == 0)
        {
            break;
        }
        else if (choice == 5)
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