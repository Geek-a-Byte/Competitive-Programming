#include<stdio.h>
#include<stdlib.h>
struct Node{
int val;
struct Node *next;
};


struct Node *head;
void print(struct Node *hd)
{
    struct Node *curr;
    curr=head;

    for(int i=0;i<3;i++){
        printf("Node No, value , address: %d %x %d  %x\n",i+1,curr,curr->val,curr->next);
        curr=curr->next;
    }

}

int main()
{


    struct Node *newNode1=(struct Node*)malloc(sizeof(struct Node));
    struct Node *newNode2=(struct Node*)malloc(sizeof(struct Node));
    struct Node *newNode3=(struct Node*)malloc(sizeof(struct Node));
    newNode1->val=15;
    head=newNode1;
    newNode1->next=newNode2;



    //struct Node *newNode2=(struct Node*)malloc(sizeof(struct Node));
    newNode2->val=30;
    newNode2->next=newNode3;

    //struct Node *newNode3=(struct Node*)malloc(sizeof(struct Node));
    newNode3->val=45;
    newNode3->next=NULL;
    printf("%d %x %x\n",head->val,&head,&newNode1);
    printf("%d %x %d %x %d %x\n",newNode1->val,newNode1,newNode2->val,newNode1->next,newNode3->val,newNode2->next);
    print(head);
}

