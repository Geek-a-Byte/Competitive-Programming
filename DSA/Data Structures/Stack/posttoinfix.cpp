#include <bits/stdc++.h>

using namespace std;

struct Stack
{
    string data;
    Stack *next;
};

Stack *top = NULL;

Stack *StackNode(string val)
{
    Stack *newNode = new Stack();
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void push(string val)
{
    Stack *newNode = StackNode(val);
    if (top == NULL)
        top = newNode;
    else
    {
        newNode->next = top;
        top = newNode;
    }
}

void pop()
{
    Stack *cur = top;
    top = top->next;
    free(cur);
}

int main()
{
    string s;
    cin >> s;

    string res = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')
        {
            res = "";

            string s1 = top->data;
            pop();
            string s2 = top->data;
            pop();

            res += "(";
            res += s2;
            res += s[i];
            res += s1;
            res += ")";

            push(res);
        }
        else
        {
            string temp = "";
            temp += s[i];
            push(temp);
        }
    }

    cout << res << endl;
}

/*
INPUT  : ABC*DEF^/G*-H*+
OUTPUT : (A+(((B*C)-((D/(E^F))*G))*H))
*/