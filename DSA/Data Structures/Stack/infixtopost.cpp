#include<bits/stdc++.h>
 
using namespace std;
 
struct Stack
{
    char data;
    Stack *next;
};
 
Stack *top = NULL;
 
Stack *StackNode(char val)
{
    Stack *newNode = new Stack();
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}
 
 
void push(char val)
{
    Stack *newNode = StackNode(val);
    if(top == NULL) top = newNode;
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
 
int precedence(char ch)
{
    if(ch=='+' || ch=='-') return 1;
    else if(ch=='*' || ch=='/') return 2;
    else if(ch=='^') return 3;
    else return 0;
 
}
 
int main()
{
    string s;
    cin>>s;
 
    string res = "";
 
    for(int  i=0 ; i<s.size(); i++)
    {
        if(s[i] == '(') push(s[i]);
        else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='^')
        {
            if(top == NULL) push(s[i]);
            else
            {
                while(precedence(s[i]) <= precedence(top->data))
                {
                    res += top->data;
                    res += " ";
                    pop();
                    if(top==NULL)
                        break;
                }
                push(s[i]);
            }
 
        }
        else if(s[i]==')')
        {
            while(top->data != '(')
            {
                res += top->data;
                res += " ";
                pop();
            }
            pop();
        }
        else
        {
            res += s[i];
            res += " ";
        }
    }
 
    while(top != NULL)
    {
        res += top->data;
        res += " ";
        pop();
    }
 
    cout<<res<<endl;
}
 
 
 
/*
INPUT : (A+(((B*C)-((D/(E^F))*G))*H))
OUTPUT: ABC*DEF^/G*-H*+
*/