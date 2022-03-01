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
void reverse()
{
    Node *curr, *prev, *next;
    curr = head;
    prev = NULL;
    next = NULL;

    while (curr != NULL)
    {
        //make the next pointer point towards curr->next
        next = curr->next;
        //rotate the curr->next to prev
        curr->next = prev;
        //now shift the prev to next node
        //remember the sequence-> prev->curr->next
        prev = curr;
        //and shift the curr to next node
        curr = next;
    }
    //shift the head to the last node which is now prev as
    //curr and next would be pointing to NULL now
    head = prev;
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
    printList();
    reverse();
    printList();

    freeTheList();
}