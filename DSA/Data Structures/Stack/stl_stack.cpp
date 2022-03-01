#include <iostream>
#include <stack>
using namespace std;
int main( )
{
    stack <int> s;  // declaration of stack

    int n;
    cout<<"enter the size of the stack:"<<endl;
    cin>>n;
    
    cout<<"enter the elements of the stack"<<endl;
    for(int i = 0;i < n; i++)
    {
        int x;
        cin>>x;
        s.push( x ) ;
    }    

    //size of stack s
    //indirectly printing n
    cout<<"Size of stack is:" <<s.size( )<<endl;

    //accessing top element from stack, it will be the last inserted element.
    cout<<"Top element of stack is:" <<s.top( ) <<endl ;

    //Now deleting all elements from stack 
    for(int i = 0;i < n;i++)
    {
        s.pop( );
    }
    cout<<"all the elements popped out of the stack successfully"<<endl;

    //Now stack is empty,so empty( ) function will return true.

    if(s.empty())
    {
        cout <<"Stack is empty."<<endl;
    }
    else
    {
        cout <<"Stack is Not empty."<<endl;
    }


    return 0;

}