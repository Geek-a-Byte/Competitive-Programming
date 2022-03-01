#include <stdio.h>

struct Node
{
    int val;
    Node * next;
};

struct LinkedList
{
    private:
        Node * head = NULL;
        Node * tail = NULL;
public:
    void push_front(int v)
    {
        Node node1;
        Node * temp = new Node;
        (*temp).val = v;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
    }
    int get_front_element()
    {
        if (head == NULL)
        {
            printf("No element\n");
            return -1;
        }
        else
            return head->val;
    }
    void display()
    {
        if (head == NULL)
            printf("No element!\n");
        else
        {
            Node * temp = head;
            while (temp != NULL)
            {
                printf("%d ", temp->val);
                temp = temp->next;
            }
            printf("\n");
        }
    }
    void dispose()
    {
        Node * temp;
        while (head != NULL)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
        printf("All elements are cleared!\n");
    }

    int pop_front()
    {
        if (head == NULL)
        {
            printf("Linked List is empty");
            return -1;
        }

        else
        {
            Node * temp = head;
            if (head == tail)
            {
                //we are deleting the last element
                tail = NULL;
            }
            head = temp->next;
            int ret = temp->val;
            delete temp;
            return ret;
        }
    }
    void push_back(int val_)
    {
        if (head == NULL)
            push_front(val_);
        else
        {
            Node * temp = new Node;
            temp->val = val_;
            temp->next = NULL;
            tail->next = temp;
            tail = temp;
        }
    }

};

class Queue
{
private:
    LinkedList l1;
public:
    void enqueue(int val)
    {
        l1.push_back(val);
    }
    int dequeue()
    {
        return l1.pop_front();
    }
    void display()
    {
        l1.display();
    }
    void dispose()
    {
        l1.dispose();
    }
};

int main()
{
    Queue Q;
    Q.enqueue(1);
    Q.enqueue(2);
    Q.enqueue(3);
    Q.enqueue(4);
    Q.enqueue(5);
    Q.display();
    int x = Q.dequeue();
    printf("Dequeued Element %d\n", x);
    x = Q.dequeue();
    printf("Dequeued Element %d\n", x);
    Q.enqueue(10);
    Q.display();
    Q.dispose();

}

