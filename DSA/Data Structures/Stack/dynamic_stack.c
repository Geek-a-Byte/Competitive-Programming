#include <stdio.h>
#include<stdlib.h>
typedef enum {
   false,true
}
bool;
int top = -1; //globally defining the value of top ,as the stack is empty .

void push (int * stack , int x , int n)
{
    if ( top == n-1 )          //if top position is the last of position of stack, means stack is full .
    {
        printf("Stack is full.Overflow condition!\n");
    }
    else
    {
        top = top +1 ;            //incrementing top position 
        stack[ top ] = x ;       //inserting element on incremented position .  
    }
}
bool isEmpty (int* stack)
{
    if ( top == -1 )  //stack is empty .
        return true ; 
    else
        return false;
}
void pop (int * stack) 
{

    if( isEmpty (stack) )
    {
        printf("Stack is empty . Underflow condition!\n") ;
    }
    else    
    {
         top = top - 1 ; //decrementing top’s position will detach last element from stack .            
    }
}
int size (int * stack)
{
    return top + 1;
}
int topElement (int * stack)
{
    return stack[top];
}
// Now lets implementing these functions on the above stack

int main( )
{
    int n;
    printf("enter the size of the stack:\n");
    scanf("%d",&n);
    int * stack=(int *)malloc(n*sizeof(int));

    while(1){
    int opt;
    printf("enter the option:\n1 for pushing new element\n2 for checking if the stack is empty or not\n3 for popping an element out of the stack\n4 for determining the current size of the stack\n5 for determining the topmost element of the stack\n6 for quitting\n");
    scanf("%d",&opt);
    if(opt==1)
    {
        int x;
        printf("Enter the element you want to insert into stack:\n");
        scanf("%d",&x);
        push(stack,x,n);
        printf("%d pushed into stack successfully\n",x);
    }
    if(opt==2)
    {
        if(isEmpty(stack))
          printf("the stack is empty\n");
        else
          printf("the stack is not empty\n");
          
         
    }
    if(opt==3)
    {
        pop(stack);
        printf("One element popped out of the stack successfully\n");
    }if(opt==4)
    {
        
        printf("the current size of the stack is:%d\n",size(stack));
        
    }if(opt==5)
    {
        printf("the topmost element of the stack is :%d\n",topElement(stack));
    
    }
    if(opt==6)
    {
        break;
    }
}
free(stack);
}