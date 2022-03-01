// using array
#include <bits/stdc++.h>
using namespace std;

int top = -1;
int n = 100;

bool isEmpty()
{
    if (top <= -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int getSize()
{
    return top + 1;
}
void push(int val, int *stack)
{
    if (top >= n - 1)
    {
        cout << "StackOverflow\n";
        return;
    }
    else
    {
        top++;
        stack[top] = val;
    }
}
void pop()
{
    if (isEmpty())
    {
        cout << "Stack EMpty\n";
        return;
    }
    else
    {
        top--;
    }
}
int peek(int *stack)
{
    return stack[top];
}
void printStack(int *stack)
{
    int n = getSize();
    for (int i = 0; i < n; i++)
    {
        cout << stack[i] << " ";
    }
    cout << endl;
}
int main()
{
    //for faster i/o

    int *stack;
    int n;
    cout << "enter the size\n";
    cin >> n;
    stack = (int *)malloc(sizeof(int) * n);
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        push(x, stack);
    }
    cout << "the size of the stack is : " << getSize() << endl;
    printStack(stack);
    pop();
    printStack(stack);
    return 0;
}