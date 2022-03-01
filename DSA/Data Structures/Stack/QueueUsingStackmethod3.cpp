#include<bits/stdc++.h>
using namespace std;

struct Queue{
    stack<int>s;
    
    //3 2 1 
    void enqueue(int x)
    {
        s.push(x);
    }


    int dequeue()
    {
        if(s.empty())
        {
            cout<<"Queue is empty"<<endl;
        }

        int x= s.top();
        s.pop();

        if(s.empty())
        {
            return x;
        }

        //recursive call
        int item = dequeue();

        s.push(x);

        return item;
    }
}