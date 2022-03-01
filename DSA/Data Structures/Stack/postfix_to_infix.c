#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
# define MAX 20
 
char str[MAX], stack[MAX];
int top = -1;
 
char pop()
{
      return stack[top--];
}
 
void push(char ch)
{
      stack[++top] = ch;
}
 
void postfix_to_infix(char expression[])
{
      int i, length;

      char item, operator;

      length = strlen(expression);
      
      printf("\nInfix Expression:\t");

      printf("%c", expression[0]);
      for(i = 1; i < length; i++)
      {
            if(expression[i] == '-' || expression[i] == '/' || expression[i] == '*'|| expression[i] == '+')
            {
                  item = pop();
                  operator = expression[i];
                  printf(" %c %c", operator, item);
            }
            else
            {
                  push(expression[i]);
            }
      }
      //printf("%c", expression[top--]);
}
 
int main()
{
      char postfix_expression[50];
      printf("\nEnter Postfix Expression:\t");
      scanf("%s", postfix_expression);
      postfix_to_infix(postfix_expression);
      printf("\n");
      return 0;
}