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
vector<int> arr;

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
void insertBegin(int val)
{
    //1.createNode
    Node *new_node = createNode(val);

    //if head == NULL, the ll is empty
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        //1.first point the new node to the node that is pointed by head
        new_node->next = head;
        //2.then point the head to the new node
        head = new_node;
    }
}

void insertAt(int pos, int val)
{
    if (head == NULL)
    {
        cout << "the linked list is empty" << endl;
        return;
    }

    Node *new_node = createNode(val);
    Node *temp = head;

    if (pos == 1)
    {
        insertBegin(val);
    }
    else
    {
        for (int i = 1; i <= pos; i++)
        {
            if (temp == NULL)
            {
                printf("Insertion is not possible\n");
            }

            if (i == pos - 1)
            {
                new_node->next = temp->next;
                temp->next = new_node;
                return;
            }
            else
            {
                temp = temp->next;
            }
        }
    }
    // printList();
}
void deleteBegin()
{
    Node *curr = head;
    arr.push_back(head->key);
    head = head->next;
    free(curr);
    printList();
}
void deleteAt(int pos)
{
    if (pos == 1)
    {
        deleteBegin();
    }
    Node *curr, *prev;
    curr = head;
    prev = head;
    for (int i = 1; i < pos; i++)
    {

        prev = curr;
        curr = curr->next;
    }
    arr.push_back(curr->key);
    prev->next = curr->next;
    free(curr);
    printList();
}
void reformList(int p, int l, int n)
{
    for (int i = 1; i <= l; i++)
    {
        deleteAt(p);
    }
    int k = 0;

    for (int i = l; i >= 1; i--)
    {
        insertAt(n, arr[k]);
        n++;
        k++;
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
    int pos_to_cut;
    cout << "enter the position to cut\n";
    cin >> pos_to_cut;
    int length;
    cout << "enter the length to cut\n";
    cin >> length;
    int new_pos;
    cout << "enter the new position to add the cutted linked list\n";
    cin >> new_pos;
    reformList(pos_to_cut, length, new_pos);
    printList();
    freeTheList();
}