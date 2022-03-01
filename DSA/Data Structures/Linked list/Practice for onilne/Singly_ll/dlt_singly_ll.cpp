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

    freeTheList();
    printList();
}