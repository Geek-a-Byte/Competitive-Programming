#include <iostream>
using namespace std;

class Queue
{
private:

double *queueArray;
int maxSize;
int front;
int rear;
int numItems;

public:

Queue(int);
~Queue(void);
void enqueue(double);
double dequeue(void);
bool isEmpty(void);
bool isFull(void);
void clear(void);

};

//Constructor


//*************************
// Constructor *
//*************************

Queue::Queue(int s)
{

queueArray = new double[s];
maxSize = s;
front = -1;
rear = -1;
numItems = 0;

}

//O(1)

//Destructor

//*************************
// Destructor *
//*************************

Queue::~Queue(void)
{

delete [] queueArray;

}

//********************************************
// Function enqueue inserts the value in num *
// at the rear of the queue. *
//********************************************
void Queue::enqueue(double num)
{

if (isFull())

cout << "The queue is full.\n";

else
{

// Calculate the new rear position
rear = (rear + 1)%maxSize;
// Insert new item
queueArray[rear] = num;
// Update item count
numItems++;
if (numItems == 1) //First element
front=0;

cout<<"after enqueuing the front is now "<<front<<endl;
cout<<"after enqueuing the rear is now "<<rear<<endl;

}

} 
//O(1)

//Dequeue operation
//*********************************************
// Function dequeue removes the value at the *
// front of the queue, and copies it into num. *
//*********************************************
double Queue::dequeue()
{

if (isEmpty())

cout << "The queue is empty.\n";

else
{
double num;
// Retrieve the front item
num = queueArray[front];
// Move front
front = (front + 1)%maxSize;
// Update item count and return num
numItems--;
// Last element deleted
if (numItems == 0)
{
    front = -1; 
    rear = -1;
}


cout<<"after dequeuing the front is now "<<front<<endl;
cout<<"after dequeuing the rear is now "<<rear<<endl;

return(num);

}

}
//O(n)

//isEmpty operation

//*********************************************
// Function isEmpty returns true if the queue *
// is empty, and false otherwise. *
//*********************************************
bool Queue::isEmpty(void)
{

bool status;
if (numItems==0) //or, if (front==-1)

status = true;

else

status = false;

return status;

}

//O(1)

//********************************************
// Function isFull returns true if the queue *
// is full, and false otherwise. *
//********************************************
bool Queue::isFull(void)
{

bool status;
if (numItems == maxSize) // or, if (rear==maxSize-1)

status = true;

else

status = false;

return status;

}

//isFull operation

//O(1)

//Clear operation

//*******************************************
// Function clear resets the front and rear *
// indices, and sets numItems to 0. *
//*******************************************
void Queue::clear(void)
{

front = -1;
rear = -1;
numItems = 0;

}

//O(1)

//Illustrating Program
// This program demonstrates the Queue class

int main()
{

Queue queue(5);
cout << "Enqueuing 5 items...\n";
// Enqueue 5 items.
for (int x = 0; x < 5; x++)
queue.enqueue(x);

// Attempt to enqueue a 6th item.
cout << "Now attempting to enqueue again...\n";
queue.enqueue(5);

// Deqeue and retrieve all items in the queue
cout << "The values in the queue were:\n";
while (!queue.isEmpty())
{

double value;
value=queue.dequeue();
cout << value << endl;

}

}