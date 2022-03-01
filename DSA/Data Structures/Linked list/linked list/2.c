#include<stdio.h>
#include<stdlib.h>
struct node{
    int val;
    struct node *next;
};
typedef struct node Node;
Node * head=NULL;

Node *createNode(int d)
{
    Node * new_node=(Node*)malloc(sizeof(Node));
    new_node->val=d;
    new_node->next=NULL;
    return new_node;
}

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

void insert_at_middle(int d,int pos)
{
    Node *new_node_middle, *temp, *cur_node;
    new_node_middle=(Node*) malloc(sizeof(Node));
    new_node_middle->val=d;
    int i=1;
    while(cur_node->next!=NULL)
    {
        cur_node=cur_node-> next;
        if(i==pos)
        {
            break;
        }
        i++;
    }
    new_node_middle->next=cur_node->next;
    cur_node->next=new_node_middle;

}

Node *search_in_the_list(int x,Node *L)
{
    if(L==NULL)
        return -1;
    else if(x==L->val)
    {
        return L;

    }
    else
        return search_in_the_list(x,L->next);

}

void print(Node *head)
{
    Node *it=head;
    while(it!=NULL)
    {
        printf("%d ",it->val);
        it=it->next;
    }
    printf("\n");

}
int main()
{
    int i,pos,opt;
    int data;
    head=createNode(100);

    while(1)
    {

    printf("Enter the option you want to select:\n");

    printf("1. Insert an element at the beginning of linked list.\n");
    printf("2. Insert an element at the end of linked list.\n");
    printf("2. Insert an element at the middle of linked list.\n");
    printf("4. Search for an element\n");
    printf("5. Delete an element from beginning.\n");
    printf("6. Delete an element from end.\n");
    printf("7. delete from the middle\n");
    printf("8. Quit.\n");
    printf("9. print the list\n");

    scanf("%d",&opt);

    printf("Enter the element:\n");
    scanf("%d",&data);

    printf("Enter the position:\n");
    scanf("%d",&pos);

        if(opt==1)
        {
            insert_at_first(data);
        }

        if(opt==2)
        {
            insert_at_last(data);
        }

        if(opt==3)
        {
            insert_at_middle(data,pos);
        }

        if(opt==4)
        {
            search_in_the_list(data,head);
        }

        /*if(opt==5)
        {

        }

        if(opt==6)
        {

        }

        if(opt==7)
        {

        }*/

        if(opt==8)
        {
           break;
        }
        if(opt==9){
          print(head);
        }
    }

}
