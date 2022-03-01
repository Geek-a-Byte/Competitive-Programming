#include<stdio.h>
#include<stdlib.h>
struct node{
    int val;
    struct node *next;
};
typedef struct node Node;
Node * head=NULL;

void insert_at_first(int d)
{
    Node * new_node_first;
    new_node_first=(Node *) malloc(sizeof(Node));

    new_node_first->val=d;
    //case 1: if The head is pointing at null i.e the list is empty

    if(head==NULL)
    {
        head=new_node_first;
        new_node_first->next=NULL;
        return;
    }

    //case 2: if the head is not pointing at null,there is a node on which the head is pointing

    new_node_first->next=head;
    head=new_node_first;


}

void insert_at_last(int d)
{
    //here the head pointer needs to be traversed to get to the last node
    // but we cant do that because we need to insert at last without changing the address of the head
    //so we will take a temp node to traverse the head

    Node *new_node_last, *temp;
    new_node_last=(Node*) malloc(sizeof(Node));

    new_node_last->val=d;

    //case 1: if The head is pointing at null i.e the list is empty

    if(head==NULL)
    {
        head=new_node_last;
        new_node_last->next=NULL;
        return;
    }
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new_node_last;
    new_node_last->next=NULL;

}

/*void insert_at_middle(int d)
{
    Node *new_node_middle, *temp, *cur_node;
    new_node_middle=(Node*) malloc(sizeof(Node));
    new_node_middle->val=d;

    new_node_middle->next=cur_node;



}
*/

int main()
{
    int i;
    int data;
    printf("Enter the element:\n");
    scanf("%d",&data);



}
