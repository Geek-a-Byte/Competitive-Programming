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

//insert_begin can be called as prepend
void insert_begin(int val)
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
    return;
}

void insertAfterNode(Node *prev, int val)
{
    Node *new_node = createNode(val);
    if (prev == NULL)
    {
        cout << "the given node cannot point to NULL" << endl;
    }
    else
    {
        new_node->next = prev->next;
        prev->next = new_node;
    }
    return;
}
//note that we cannot insert at last position using insertAt
//we cannot insert at the first position using insertAt if the list is empty or head=null
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
        insert_begin(val);
        return;
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
}

//insertEnd can be called append
void insertEnd(int val)
{
    Node *new_node = createNode(val);
    //if the linked list is empty , then  the head pointer will be the tail pointer itself
    if (head == NULL)
    {
        insert_begin(val);
    }
    else
    {
        //1.traverse to the end of the list
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        //2.point the last node to new node
        temp->next = new_node;
    }
    return;
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
    cout << "enter\n0 -> break\n1 -> InsertBegin\n2 -> InsertAt\n3 -> InsertEnd\n4 -> InsertAfterNode\n5->sort\n";
    int choice;
    while (1)
    {
        cin >> choice;

        if (choice == 1)
        {
            cout << "insert a value at first position: " << endl;
            int inp;
            cin >> inp;
            insert_begin(inp);
            printList();
        }
        else if (choice == 2)
        {

            cout << "insert a value at random position: \ninsert the position" << endl;
            int pos, inp;
            cin >> pos >> inp;
            int size = getSize();
            cout << "the size of the linked list is " << size << "\n";
            if (pos < 1 || pos >= size + 1)
            {
                cout << "invalid position" << endl;
            }
            else
            {
                insertAt(pos, inp);
                printList();
            }
        }
        else if (choice == 3)
        {
            cout << "insert a value at end position: " << endl;
            int inp;
            cin >> inp;
            insertEnd(inp);
            printList();
        }
        else if (choice == 4)
        {
            if (head == NULL)
            {
                cout << "the given node cannot point to NULL" << endl;
            }
            else
            {
                cout << "insert a value after a given node: " << endl;
                int inp;
                cin >> inp;
                //note that you have to ensure that is head->next is null it will run fine as a condition is there to
                //handle it but can't pass head->next->next as it is not null and hence the program will crash
                insertAfterNode(head->next, inp);
                printList();
            }
        }
        else if (choice == 0)
        {

            break;
        }
        else if (choice == 5)
        {

            sort();
            printList();
        }
        else
        {
            cout << "invalid choice" << endl;
        }
    }
    freeTheList();
}