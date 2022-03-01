//using array
#include <bits/stdc++.h>
#define s 10
using namespace std;

class Queue
{
    int *arr;
    int capacity; //maxsize
    int front;
    int rear;
    int count; //currentsize
public:
    Queue(int size)
    {
        capacity = size;
        arr = new int[size];
        front = 0;
        rear = -1;
        count = 0;
    }
    ~Queue()
    {
        delete[] arr;
    }
    int size()
    {
        return count;
    }
    bool isFull()
    {
        if (count >= capacity)
        {
            return 1;
        }
        return 0;
    }
    bool isEmpty()
    {
        if (count <= 0)
        {
            return 1;
        }
        return 0;
    }
    void enqueue(int val)
    {
        if (isFull())
        {
            cout << "the queue is full\n";
            return;
        }
        else
        {
            //rear initially -1
            rear = (rear + 1) % capacity;
            arr[rear] = val;
            count++;
        }
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "The queue is empty\n";
        }
        else
        {
            front = (front + 1) % capacity;
            count--;
        }
    }
    int peek()
    {
        if (isEmpty())
        {
            cout << "The queue is empty\n";
        }

        return arr[front-1];
    }
    void printQueue()
    {
        for (int i = 0; i < count; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Queue q(5);
    int n;
    cin >> n;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        q.enqueue(x);
    }
    q.printQueue();
    q.dequeue();
    q.printQueue();
    //print the peek
    cout << q.peek() << endl;
    if (q.isEmpty())
        cout << "Queue Is Empty\n";
    else
        cout << "Queue Is Not Empty\n";
}