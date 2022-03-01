#include <bits/stdc++.h>
using namespace std;
#define n 100
int top = -1;
int push(char *stack, char ch)
{
    //check overflow
    if (top >= 100)
    {
        cout << "stack overflow\n";
        return 0;
    }
    else
    {
        top++;
        stack[top] = ch; //push char
        return 1;
    }
}
int pop()
{
    //check underflow
    if (top <= -1)
    {
        cout << "stack is empty\n";
        return 0;
    }
    else
    {
        top--;
        return 1;
    }
}
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
void printStack(char *stack)
{
    for (int i = 0; i <= top; i++)
    {
        cout << stack[i];
    }
    cout << endl;
}
void isBalanced(char *stack)
{
    int popped;
    for (int i = 36; i >= 0; i--)
    {
        if (stack[i] != '(' || stack[i] != ')' || stack[i] != '{' || stack[i] != '}' || stack[i] != '[' || stack[i] != ']')
        {
            popped = pop();
            if (popped)
            {
                cout << "pop successful\n";
            }
            else
            {
                cout << "pop unsucessfull\n";
            }
        }
    }
    printStack(stack);
}
int main()
{
    char arr[100];

    int l;
    cin >> l; //size of the array

    char *stack = (char *)malloc(sizeof(char) * l); //memory allocation
    int pushed;
    for (int i = 0; i < 36; i++)
    {
        cin >> arr[i];
        pushed = push(stack, arr[i]);
        if (pushed)
        {
            cout << "push successful\n";
        }
        else
        {
            cout << "push unsuccessful\n";
        }
    }
    printStack(stack);
    isBalanced(stack);
}