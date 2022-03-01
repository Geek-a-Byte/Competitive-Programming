#include<bits/stdc++.h>
using namespace std;

struct Queue{
   stack<int>s1,s2;

   void enQueue(int x)
   {
       s1.push(x);
   }
   //3 2 1 akare thakbe mane top e 3 thakbe then 2 then 1 
   
   //amake 1 2 3 akare dequeue korte hobe
   //arekta stack lagbe jekhane 1 2 3 akare rakha jabe taile top e 1 thakbe
   int dequeue()
   {
        if(s1.empty() && s2.empty())
        {
            cout<<"queue is empty"<<endl;

        }

        if(s2.empty())
        {
            while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
            }
        }

        int x=s2.top();
        s2.pop();
        return x;
   }

};

int main()
{
    Queue q;
    q.enQueue(1); 
    q.enQueue(2); 
    q.enQueue(3); 
  
    cout << q.dequeue() << endl; 
    cout << q.dequeue() << endl; 
    cout << q.dequeue() << endl; 



}