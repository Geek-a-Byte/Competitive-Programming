#include <bits/stdc++.h>

using namespace std;

struct Stack
{
    int data;
    Stack *next;
};

Stack *StackNode(int val)
{
    Stack *newNode = new Stack();
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

bool isEmpty(Stack *ptr)
{
    if (ptr == NULL)
        return true;
    return false;
}

void push(Stack **ptr, int val)
{
    Stack *newNode = StackNode(val);
    if (isEmpty(*ptr))
        *ptr = newNode;
    else
    {
        newNode->next = *ptr;
        *ptr = newNode;
    }
}

void pop(Stack **ptr)
{
    if (isEmpty(*ptr))
        return;
    else
    {
        Stack *cur = *ptr;
        *ptr = (*ptr)->next;
        free(cur);
    }
}

int Top(Stack *ptr)
{
    if (isEmpty(ptr))
    {
        return -1;
    }
    else
    {
        return ptr->data;
    }
}

void PrintMovement(string from, string to, int disk)
{
    cout << "Move the disk " << disk << " from " << from << " to " << to << endl;
}

void moveDisk(Stack **from, Stack **to, string s, string d)
{
    if (isEmpty(*from))
    {
        push(&(*from), Top(*to));
        PrintMovement(d, s, Top(*to));
        pop(&(*to));
    }
    else if (isEmpty(*to))
    {
        push(&(*to), Top(*from));
        PrintMovement(s, d, Top(*from));
        pop(&(*from));
    }
    else if (Top(*from) > Top(*to))
    {
        push(&(*from), Top(*to));
        PrintMovement(d, s, Top(*to));
        pop(&(*to));
    }
    else
    {
        push(&(*to), Top(*from));
        PrintMovement(s, d, Top(*from));
        pop(&(*from));
    }
}

void AllMoves(int n, Stack *src, Stack *dest, Stack *aux)
{
    int t_moves = pow(2, n) - 1;

    string s = "Source";
    string d = "Destination";
    string a = "Auxiliary";

    if (n % 2 == 0)
    {
        string temp = d;
        d = a;
        a = temp;
    }

    for (int i = 1; i <= t_moves; i++)
    {
        if (i % 3 == 1)
            moveDisk(&src, &dest, s, d);
        else if (i % 3 == 2)
            moveDisk(&src, &aux, s, a);
        else if (i % 3 == 0)
            moveDisk(&aux, &dest, a, d);
    }
}

int main()
{
    cout << "Enter the number of disks : ";
    int n;
    cin >> n;

    Stack *src = NULL;
    Stack *dest = NULL;
    Stack *aux = NULL;

    for (int i = n; i > 0; i--)
    {
        push(&src, i);
    }

    AllMoves(n, src, dest, aux);
}
