#include <iostream>
using namespace std;

class Queue
{
private:

//now we have to define each element of an array as a node 
struct QueueNode
{

int value;
QueueNode *next;

};

//front and rear will also be two itereating nodes 
QueueNode *front;
QueueNode *rear;

//num of items is actually num of nodes 
int numItems;

public:

Queue();
~Queue();
void enqueue(double num);
double dequeue();
bool isEmpty();
void clear();

};

//Constructor and Destructor

//************************
// Constructor *
//************************

Queue::Queue()
{

//as front and rear are nodes now u have to define them as null pointing nodes at first
front = NULL;
rear = NULL;

////before enqueing anything num of nodes will be 0
numItems = 0;

}

//************************
// Destructor *
//************************

Queue::~Queue()
{

clear();

}

//O(1)

//O(n)

//Enqueue operation

//********************************************
// Function enqueue inserts the value in num *
// at the rear of the queue. *
//********************************************
void Queue::enqueue(double num)
{

//node declaring is done in class queue 
//now during enqueue we have to ensure that there is specific memory allocation as it is a dynamic queue
//the memory need to be both for the value and the address of the next pointer
//so we need to take the size of the queueNode
//and then assign it for the new node
QueueNode *newNode = new QueueNode;

//newnode's value will be num
newNode->value = num;

//newnode's next address will be null
newNode->next = NULL;


if (isEmpty())
{

//if there is no node front and rear would be the same node(newNode)and they will be pointing to null as the new node is pointing to null at first
front = newNode;
rear = newNode;

}
else
{

rear->next = newNode;
rear = newNode;

}

//enqueue kore num 1 barabo
numItems++;

}

//O(1)

//Dequeue operation

//**********************************************
// Function dequeue removes the value at the *
// front of the queue, and copies it into num. *
//**********************************************
double Queue::dequeue()
{

QueueNode *temp;
if (isEmpty())
   cout << "The queue is empty.\n";

else
{

double num = front->value;

temp = front->next;

//delete the memory of the front
delete front;
front = temp;
numItems--;
return(num);

}

} 
//O(1)

//isEmpty operation

//*********************************************
// Function isEmpty returns true if the queue *
// is empty, and false otherwise. *
//*********************************************
bool Queue::isEmpty()
{

bool status;
if (numItems==0) // or, if (front==NULL)

status = true;

else

status = false;

return status;

}

//O(1)

//Clear operation

//********************************************
// Function clear dequeues all the elements *
// in the queue. *
//********************************************
void Queue::clear()
{

int value; // Dummy variable for dequeue

while(!isEmpty())

value = dequeue();

}

//O(n)

//Illustrating Program
// This program demonstrates the Queue class
//#include <iostream>
int main()
{

Queue queue;
cout << "Enqueuing 5 items...\n";
// Enqueue 5 items.
for (int x = 0; x < 5; x++)
queue.enqueue(x);

// Deqeue and retrieve all items in the queue
cout << "The values in the queue were:\n";
while (!queue.isEmpty())
{

double value;
value=queue.dequeue();
cout << value << endl;

}

}