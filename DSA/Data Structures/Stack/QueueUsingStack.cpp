#include<bits/stdc++.h>
using namespace std;

struct Queue
{
  stack<int>s1,s2;

  //consider s1 as the queue
  //x element enqueue korbo stack e (s1 e)
  void enqueue(int x)
  {
      //move all elements from s1 to s2
      //s1 jotokkhonn khali hobe na s1 theke pop hoite thakbe and s2 te push korte thakbe
      while(!s1.empty())
      {
          s2.push(s1.top());
          s1.pop();
      }
      
      //jei element stack e enqueue korte chai line er pichon diye sheita push korbo shobar age 
      s1.push(x);

      //push everything back to s1
      while(!s2.empty())
      {
          s1.push(s2.top());
          s2.pop();
      }
  }  

  //Dequeue an item from the queue
  //dequeue hocche stack er shamne theke or shobar upor theke element ner kore neya 
  //khali pop korlei hobe

  int dequeue()
  {
      if(s1.empty())
      {
           cout<<"Queue is empty"<<endl;
      }

      //return top of s1

      int x=s1.top();
      s1.pop();
      return x;
  }    

  
};

int main()
{
    Queue q;
    //as per the algorithm 1 2 3 akare thakbe mane top e thakbe 1 then 2 then 3 
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);


    //as per the algorthm 1 2 3 akare pop korbe
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
     
    return 0;
}