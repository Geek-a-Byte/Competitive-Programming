#include <stdio.h>
typedef enum {
   false,true
}
bool;
int top = -1; //globally defining the value of top ,as the stack is empty .

void push (int stack[ ] , int x , int n)
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
bool isEmpty ( )
{
    if ( top == -1 )  //stack is empty .
        return true ; 
    else
        return false;
}
void pop () 
{

    if( isEmpty ( ) )
    {
        printf("Stack is empty . Underflow condition!\n") ;
    }
    else    
    {
         top = top - 1 ; //decrementing top’s position will detach last element from stack .            
    }
}
int size ( )
{
    return top + 1;
}
int topElement (int stack[])
{
    return stack[top];
}
// Now lets implementing these functions on the above stack

int main( )
{
    int stack[ 3 ];
    // pushing element 5 in the stack .
    push(stack , 5 , 3 ) ;

    printf("Current size of stack is %d\n" ,size ( )) ;

    push(stack , 10 , 3);
    push (stack , 24 , 3) ;

    printf("Current size of stack is %d\n" ,size ( )) ;

    //As now the stack is full ,further pushing  will show overflow condition .
    push(stack , 12 , 3) ;

    //Accessing the top element .
    printf("The current top element in stack is %d\n" ,topElement(stack));

    //now removing all the elements from stack .
    for(int i = 0 ; i < 3;i++ )
        pop( );
    printf("Current size of stack is %d\n" ,size ( )) ;

    //as stack is empty , now further popping will show underflow condition .
    pop ( );

}