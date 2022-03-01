//if front and rear are same -> queue is empty

#include<iostream>
#include<stdio.h>
using namespace std;

class Queue{
    public:
    int front=-1;
    int rear=-1;
    int array[100];
    int isEmpty()
    {
        if(rear==front)
           return 1;
        else
        {
            return 0;
        }
        
    }
    void enqueue(int x)
    {
         rear++;
         array[rear]=x;
    }
    int dequeue()
    {
         front++;
         return array[front];
    }
    void print(int array[],int r,int f)
    {
        cout<<"rear is "<<r<<" & front is "<<f<<endl;
        
        //int i=0;
         while(f<r)
         {
             cout<<array[f+1]<<endl;
             f++;
         }

    }

};


int main()
{
    Queue q;
    //f=-1
    //r=-1

    q.enqueue(0);
    //r=0

    q.enqueue(1);
    //r=1

    q.enqueue(2);
    //r=2

    q.enqueue(3);
    //r=3

    q.enqueue(4);
    //r=4

    q.enqueue(5);
    //r=5

    //q.enqueue(7);

    //int w=q.dequeue();
    //int y=q.dequeue();
    //int z=q.dequeue();
 
    //printf("%d %d %d is dequeued\n",w,y,z);

    //f=-1,r=5
    //i= -1, 0, 1 , 2, 3, 4
    q.print(q.array,q.rear,q.front);
    for(int i=q.front;i<q.rear;i++)
    {
        q.dequeue();
        //f=0
        //f=1
        //f=2
        //f=3
        //f=4
        //f=5

    }
    //f=5
    q.print(q.array,q.rear,q.front);

}