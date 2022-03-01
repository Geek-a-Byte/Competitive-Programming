#include<stdio.h>

typedef struct node Node;

struct node{
    int data;
    Node *next;
};

Node *head;
head=NULL;


//create a node
Node *createNode(int item,Node *next)
{
    Node *new;
    new=(Node*)malloc(sizeof(Node));
    if(new==NULL)
    {
        printf("error.new node could not be created.");
        exit(1);
    }
    new->data=item;
    new->next=next;
    return new;
}

//prepend a node at first of the list 
//prepending means to add a node at the very beginning of linked list

Node *prepend(int item,Node *head)
{

}
int main()
{
    //creating a node pointing to NULL
    Node *n1,*n2;
    n1=createNode(10,NULL);
    head=prepend(20,n1);
    printf("first node data: %d\n",head->data);
    n2=head->next;
    printf("second data is:\n",n2->data);

    //printf("%d\n",n1->data);
    return 0;
}