#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int key;
    Node *prev;
    Node *next;
} Node;

Node *head = NULL;
Node *tail = NULL;
Node *createNode(int key)
{
    //create new node
    Node *newNode = new Node();
    newNode->key = key;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

//insert at first position
int insertBegin(int val)
{

    Node *newNode = createNode(val);
    if (head == NULL)
    {
        head = newNode;
        tail = head;
        return 1;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return 1;
    }
    return 0;
}

//insert at last position
int insertEnd(int val)
{
    Node *newNode = createNode(val);
    if (head == NULL)
    {
        head = newNode;
        tail = head;
        return 1;
    }
    else
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
        return 1;
    }
    return 0;
}

int insertAt(int pos, int val)
{
    if (pos == 0)
    {
        //pos=0 is first position
        int res = insertBegin(val);
        return res;
    }
    Node *curr = head;
    Node *newNode = createNode(val);
    //travesinf thorugh the linked list to get to the specific position
    for (int i = 0; i < pos - 1; i++)
    {
        if (curr == NULL)
        {
            return 0;
        }
        curr = curr->next;
    }
    if (curr == tail)
    {
        //cur= tail means we have reached to the end
        int res = insertEnd(val);
        return res;
    }
    else
    {
        //inserting the newnode at a specific position
        newNode->next = curr->next;
        newNode->prev = curr;
        curr->next->prev = newNode;
        curr->next = newNode;
        return 1;
    }
}

int deleteAt(int val)
{
    if (head == NULL)
    {
        return 0;
    }
    else if (head->next == NULL)
    {
        //if the array size is 1
        head = NULL;
        tail = NULL;
        return 1;
    }
    else
    {
        Node *curr = head;
        while (curr != NULL)
        {
            //if the value is found then break
            if (curr->key == val)
            {
                break;
            }
            curr = curr->next;
        }
        if (curr->next == NULL)
        {
            tail->prev->next = NULL;
            tail = tail->prev;
            free(curr);
            return 1;
        }
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        free(curr);
        return 1;
    }
}

int swapnode(int pos1, int pos2)
{

    Node *curr1 = head;
    Node *curr2 = head;

    for (int i = 0; i < pos1 - 1; i++)
    {
        if (curr1 == NULL)
        {
            return 0;
        }
        curr1 = curr1->next; //getting to the node of pos1
    }
    for (int i = 0; i < pos2 - 1; i++)
    {
        if (curr2 == NULL)
        {
            return 0;
        }
        curr2 = curr2->next; //getting to the node of pos2
    }

    int val1 = curr1->key;
    int val2 = curr2->key;

    int res1 = deleteAt(val1);
    int res2 = deleteAt(val2);
    int res3 = insertAt(pos1, val1);
    int res4 = insertAt(pos2, val2);
    //printLL();
    if (res1 && res2 && res3 && res4)
        return 1;
    else
    {
        return 0;
    }
}

void printLL()
{
    Node *curr_for = head;
    Node *curr_back = tail;
    cout << "forward traversal\n";
    while (curr_for != NULL)
    {
        cout << curr_for->key << " ";
        curr_for = curr_for->next;
    }
    cout << endl;
    cout << "backward traversal\n";
    while (curr_back != NULL)
    {
        cout << curr_back->key << " ";
        curr_back = curr_back->prev;
    }
    cout << endl;
}

int main()
{

    int choice;
    while (1)
    {
        cout << "Menu:\n1. InsertNode \n2.DeleteNode \n3.SwapNode \n4.PrintArray \n5.Quit \n ";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter element and position :\n ";
            int pos, data;
            cin >> data >> pos;
            int res = insertAt(pos, data);
            if (res)
            {
                cout << "insertion successful\n";
            }
            else
            {
                /* code */
                cout << "insertion unsuccessful\n";
            }
        }
        else if (choice == 2)
        {
            cout << "enter the val\n";
            int data;
            cin >> data;
            int res = deleteAt(data);
            if (res)
            {
                cout << "deletion successful\n";
            }
            else
            {
                /* code */
                cout << "deletion unsuccessful\n";
            }
        }
        else if (choice == 3)
        {
            int pos1, pos2;
            cin >> pos1 >> pos2;
            int res = swapnode(pos1, pos2);
            if (res)
            {
                cout << "swapping successful\n";
            }
            else
            {
                /* code */
                cout << "swapping unsuccessful\n";
            }
        }
        else if (choice == 4)
        {
            printLL();
        }
        else
        {
            break;
        }
    }
}