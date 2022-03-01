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
Node *createNode(int val)
{
    Node *newNode = new Node();
    newNode->key = val;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void sort()
{
    int swapped;
    Node *curr;
    if (head == NULL)
    {
        return;
    }
    do
    {
        /* code */
        swapped = 0;
        curr = head;
        while (curr->next != NULL)
        {
            if (curr->key > curr->next->key)
            {
                swap(curr->key, curr->next->key);
                swapped = 1;
            }
            curr = curr->next;
        }
    } while (swapped == 1);
}
void insertBegin(int val)
{
    Node *newNode = createNode(val);
    if (head == NULL)
    {
        head = newNode;
        tail = head;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}
void insertEnd(int val)
{
    Node *newNode = createNode(val);
    if (head == NULL)
    {
        head = newNode;
        tail = head;
    }
    else
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}
void insertAt(int pos, int val)
{
    if (pos == 1)
    {
        insertBegin(val);
        return;
    }
    Node *newNode = createNode(val);
    Node *curNode = head;
    int i;
    for (i = 1; i < pos - 1; i++)
    {

        if (curNode == NULL)
        {
            cout << "Insertion not possible\n";
            return;
        }

        curNode = curNode->next;
    }
    if (curNode == tail)
        insertEnd(val);
    else
    {
        newNode->next = curNode->next;
        newNode->prev = curNode;
        curNode->next->prev = newNode;
        curNode->next = newNode;
    }
}
void DeleteFirst()
{
    if (head == NULL)
    {
        cout << "No list is created!\n";
        return;
    }
    else if (head->next == NULL)
    {
        head = NULL;
        tail = NULL;
        return;
    }
    else
    {
        //imp if the list is only of one size

        Node *curr = head;
        head = head->next;
        head->prev = NULL; //must write or program crashes
        free(curr);
    }
}
void DeleteEnd()
{

    if (head == NULL)
    {
        cout << "No list is created!\n";
    }
    else if (head->next == NULL)
    {
        head = NULL;
        tail = NULL;
        return;
    }
    else
    {
        Node *curr = tail;
        tail->prev->next = NULL;
        tail = tail->prev;
        free(curr);
    }
}
int getSize()
{
    int count = 0;
    Node *curr = head;
    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    return count;
}
void DeleteAt(int pos)
{
    if (head == NULL)
    {
        cout << "no deletion possible\n";
    }
    else if (head->next == NULL)
    {
        head = NULL;
        tail = NULL;
        return;
    }
    else if (pos == 1)
    {
        DeleteFirst();
    }
    else if (pos == getSize())
    {
        DeleteEnd();
    }
    else
    {

        Node *curr = head;
        for (int i = 1; i <= pos; i++)
        {

            curr = curr->next;
            //important
            if (curr == NULL)
            {
                cout << "deletion not possible" << endl;
                return;
            }
        }

        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        free(curr);
    }
}
int SearchfromHead(int val)
{
    if (head == NULL)
    {
        cout << "the list is empty\n";
    }
    else
    {
        int index = 1;
        Node *curr = head;
        while (curr != NULL)
        {
            if (curr->key == val)
            {
                return index;
            }
            index++;
            curr = curr->next;
        }
    }
    return -1;
}
void reverse()
{
    Node *temp = NULL;
    Node *curr = head;
    while (curr != NULL)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    //empty list or list with one node
    if (temp != NULL)
    {
        head = temp->prev;
    }
}
int SearchfromTail(int val)
{
    if (head == NULL)
    {
        cout << "the list is empty\n";
    }
    else
    {
        int index = 1;
        Node *curr = tail;
        while (curr != NULL)
        {
            if (curr->key == val)
            {
                return index;
            }
            index++;
            curr = curr->prev;
        }
    }
    return -1;
}
void printfromHead()
{
    if (head == NULL)
    {
        cout << "the list is empty\n";
        return;
    }
    else
    {
        cout << "list from head :";
        Node *curr = head;
        while (curr != NULL)
        {
            cout << curr->key << " ";
            curr = curr->next;
        }
        cout << endl;
    }
}
void printfromTail()
{
    if (head == NULL)
    {
        cout << "the list is empty\n";
        return;
    }
    else
    {
        cout << "list from tail :";
        Node *curr = tail;
        while (curr != NULL)
        {
            cout << curr->key << " ";
            curr = curr->prev;
        }
        cout << endl;
    }
}
void freeTheList()
{
    Node *curr;
    while (head != NULL)
    {
        curr = head;
        head = head->next;
        free(curr);
    }
}

int main()
{
    //for faster i/o
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, data;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> data;
        Node *new_Node = createNode(data);
        if (head == NULL)
        {
            head = new_Node;
            tail = head;
        }
        else
        {
            tail->next = new_Node;
            new_Node->prev = tail;
            tail = new_Node;
        }
    }
    //sort the list
    sort();
    printfromHead();
    //rversing the list
    reverse();
    printfromHead();
    cout << "after deleting first\n";
    //DeleteFirst();
    printfromHead();
    cout << "after deleting last\n";
    //DeleteEnd();
    cout << "after deleting at 3\n";
    DeleteAt(3);
    printfromHead();
    cout << "after inserting at begin\n";
    insertBegin(100);
    cout << "after inserting at last\n";
    insertEnd(500);
    printfromHead();
    cout << "after inserting at a pos\n";
    insertAt(1, 400);
    printfromHead();
    insertAt(9, 400);
    printfromHead();

    int s_h = SearchfromHead(10);
    if (s_h != -1)
    {
        cout << "From First 10 found at " << s_h << endl;
    }
    else
    {
        cout << "Not found\n";
    }
    int s_l = SearchfromTail(20);
    if (s_l != -1)
    {
        cout << "From Last 20 found at " << s_l << endl;
    }
    else
    {
        cout << "Not found\n";
    }
    printfromTail();
    freeTheList();

    return 0;
}