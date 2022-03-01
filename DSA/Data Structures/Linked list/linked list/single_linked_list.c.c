#include<stdio.h>
#include<stdlib.h>
typedef enum {
   false,true
}
bool;

typedef struct node Node;

struct node{
    int data;
    Node *next;
};

Node *head;



//create a node
Node *createNode(int item,Node *next)
{
    Node *new_node;
    new_node=(Node*)malloc(sizeof(Node));
    if(new_node==NULL)
    {
        printf("error.new node could not be created.");
        exit(1);
    }
   new_node->data=item;
    new_node->next=next;
    return new_node;
}

//prepend a node at first of the list
//prepending means to add a node at the very beginning of linked list

Node *prepend(int item,Node *head)
{
   Node *new_node=createNode(item,head);
   return new_node;
}

//append a node at the end of the list
//appending means adding a node at the end of a linked list

Node *append(int item,Node *head)
{
    //as we are creating the last new node, so it would be pointing to NULL

    Node *new_node=createNode(item,NULL);


    //if the head is NULL then the linked list is empty, so we should return the new node so that it can be assigned to head
    if(head==NULL)
    {
        return new_node;
    }

    //and if the head is not NULL we have to find the last node so we will take a curr node to traverse to the last/end of the linked list
    //head should not be changed
    Node* curr_node;
    curr_node=head;

    //when next of curr would be null we will at the last node
    while(curr_node->next!=NULL)
    {
        curr_node=curr_node->next;
    }

    //assign the new node at the last node which is now the current node
    curr_node->next=new_node;

    //now return the head to access the full linked list
    return head;
}

//inserting a node in the middle

void insert(int item,Node *head,int pos)
{
    Node *curr=head;
    Node *new_node;
    int i=2;
    while(i<pos){
         curr=curr->next;
         i++;
    }

     new_node=createNode(item,curr->next);

     curr->next=new_node;
}

//counting the number of nodes in a linked list

int count(Node *head)
{
    Node *curr_node=head;
    int c=0;
    while(curr_node!=NULL)
    {
        curr_node=curr_node->next;
        c++;
    }
    return c;
}

int pos_of_a_node(int item,Node *head)
{
    Node *curr_node=head;
    int c=1;
    while(curr_node!=NULL)
    {
        if(curr_node->data==item)
        {
            return c;
        }
        curr_node=curr_node->next;
        c++;
    }

}

//searching a node in the list

Node *search(Node *head,int item)
{
    Node *curr_node=head;

    while(curr_node!=NULL)
    {
        if(curr_node->data==item)
        {
            return curr_node;
        }
        curr_node=curr_node->next;

    }
}

//almost the same as search -LOOKUP

bool lookup(int item,Node *head)
{
    Node *curr;
    curr=head;
    if(curr==NULL)
        return false;
    else if(item==curr->data)
        return true;
    else
        return lookup(item,curr->next);
}

//removing a node from the list

Node *remove_node(Node *head,Node *rem)
{
    //case 1: the list contains only one node
    if(rem==head)
    {
        head=rem->next;
        free(rem);
        return head;
    }

    //case 2: the list contains several nodes and I want to remove any node
    //in this case i have to find the node that lies before the "rem" node which i want to remove

    Node *current_node=head;

    while(current_node!=NULL)
    {
        if(current_node->next==rem)
            break;

        current_node=current_node->next;
    }

    //case 3: if the current node which is now the node before the rem node
    //then actually there is no node to remove
    //because current node is nUll itself so the rem node will not be available in the list actually
    if(current_node==NULL)
    {
        return head;
    }

    current_node->next=rem->next;
    free(rem);
    return head;


}

Node *remove_data(int item,Node *head)
{
    Node *rem,*prev_of_rem=NULL;
    rem=head;

    //if i want to remove the first node's data
    if(rem->data==item)
    {
           remove_node(head,rem);
    }

    //if i want to remove any other data rather than first node's one
    else{
    while(rem!=NULL)
    {
        if(rem->data==item)
            break;
        prev_of_rem=rem;
        rem=rem->next;
    }
    prev_of_rem->next=rem->next;

       free(rem);

       return head;
    }
}



//print the linked list

void print(Node *head)
{
    Node *curr_node=head;

    //here if we use curr_node->next!= NULL then we will not be able to print the data of the last node because the loop will break
    while(curr_node!=NULL)
    {

        printf("%d ",curr_node->data);
        curr_node=curr_node->next;

    }
    printf("\n");
}
int main()
{
    //creating a node pointing to NULL
    /*Node *n1,*n2;
    n1=createNode(10,NULL);
    printf("%d\n",n1->data);

    //the value of the new node should be given as data and the address of the next node n1 should be given as next

    head=prepend(20,n1);

    printf("first node data: %d\n",head->data);

    n2=n1;
    printf("second node data is: %d\n",n2->data);
   */


    /*
    Node *n1,*n2,*head,*n3;
    n1=createNode(10,NULL);
    head=n1;

    head=prepend(20,head);

    n2=head;

    printf("first data=%d\n",n2->data);

    n3=n2->next;

    printf("second data=%d\n",n3->data);
    return 0;
    */

    /*
    Node *head;
    head=createNode(10,NULL);

    print(head);
    //10

    head=prepend(20,head);

    print(head);
    //20 10

    head=append(30,head);

    print(head);
    //20 10 30

    printf("The number of total nodes: %d\n",count(head));

    Node *searchedNode;
    int pos;

    searchedNode=search(head,20);
    pos=pos_of_a_node(20,head);

    printf("The searched data was %d and its position is %d" ,searchedNode->data,pos);

    return 0;
    */

    /*
    Node *n1,*head,*n2;

    n1=createNode(10,NULL);

    head=n1;

    print(head);
    //10

    head=prepend(20,head);

    print(head);
    //20 10

    head=append(30,head);

    print(head);
    //20 10 30

    head=remove_node(head,n1);

    print(head);
    //20 30

    n2=head;

    head=remove_node(head,n2);

    print(head);

    //30

    n2=head;

    head=remove_node(head,n2);

    print(head);
    //nothing
    printf("Nothing to print\n");


    return 0;
    */


    Node *n1,*head,*n2;

    n1=createNode(10,NULL);

    head=n1;

    print(head);
    //10

    head=prepend(20,head);

    print(head);
    //20 10

    head=append(30,head);

    print(head);
    //20 10 30
    bool f_or_t=lookup(30,head);
    if(f_or_t==true)
        printf("The looked up is there in the list\n");
    else
        printf("The looked up is NOT there in the list\n");

    insert(40,head,4);
    print(head);

    head=remove_data(10,head);

    print(head);
    //20 30

    head=remove_data(20,head);

    print(head);

    //30

    head=remove_data(30,head);

    print(head);
    //nothing
    printf("Nothing to print\n");


    return 0;

}
