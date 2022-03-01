#include <stdio.h>

struct Node
{
    int val;
    Node * prev;
    Node * next;

    Node(int v)
    {
        val = v;
        prev = NULL;
        next = NULL;
    }
};

class DoubleLinkedList
{
    Node * head;
    Node * tail;
public:
    DoubleLinkedList()
    {
        head = NULL;
        tail = NULL;
    }
    void push_front(int val_)
    {
        Node * temp = new Node(val_);

        temp->val = val_;
        temp->prev = NULL;
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            temp->prev = NULL;
            temp->next = head;
            head->prev = temp;
            head = head->prev;
        }
    }

    void push_back(int v)
    {

        if (head == NULL)
            push_front(v);
        else
        {
            Node * temp = new Node(v);
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
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
    void revDisplay()
    {
        if (tail == NULL)
            printf("No element!\n");
        else
        {
            Node * temp = tail;
            while (temp != NULL)
            {
                printf("%d ", temp->val);
                temp = temp->prev;
            }
            printf("\n");
        }
    }
    int pop_front()
    {
        if (head == NULL)
        {
            printf("List is empty\n");
            return -1;
        }
        else if (head == tail)
        {
            Node * temp;
            temp = head;
            head = NULL;
            tail = NULL;
            int x = temp->val;
            delete temp;
            return x;
        }
        else
        {
            Node * temp;
            temp = head;
            head = head->next;
            ///head = NULL;
            ///tail = NULL;
            int x = temp->val;
            delete temp;
            head->prev = NULL;
            return x;
        }
    }

    int pop_back()
    {
        if ((head == NULL)|| (head == tail))
            return pop_front();
        else
        {
            Node *temp;
            temp = tail;
            tail = tail->prev;
            int x = temp->val;
            delete temp;
            tail->next = NULL;
            return x;
        }
    }

};

class Deque
{
    DoubleLinkedList l1;
public:
    void push_front(int v)
    {
        l1.push_front(v);
    }
    void push_back(int v)
    {
        l1.push_back(v);
    }
    int pop_front()
    {
        return l1.pop_front();
    }
    int pop_back()
    {
        return l1.pop_back();
    }
};

int main()
{
    DoubleLinkedList l1;
    l1.push_front(10);
    l1.push_front(20);
    l1.push_front(30);
    l1.display();
    l1.revDisplay();
    l1.push_back(100);
    l1.display();
    l1.revDisplay();
    int y = l1.pop_front();
    printf("popped %d\n", y);
    l1.display();
    l1.revDisplay();
    printf("Hello");
}
