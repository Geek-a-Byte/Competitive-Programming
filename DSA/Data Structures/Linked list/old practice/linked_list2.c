#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int value;
    struct node *next;
};
typedef struct node node;
void print(int *head)
{
    node * temp;
    temp=head;
    while(temp!=NULL)
    {

        printf("%d ",temp->value);
        temp=temp->next;
    }
}
//first iteration : head(NuLL), new node(first node) er value nilam, first node(Null), head jehetu null chilo now it will be pointing to first node
//second iteration : second node er value nibo and second node (null), but ekhon head null na, ekhon temp head ke point korbe, temp ultimately first node ke point korbe which is null tai while loop e jabe na
//temp ->next e ekhon second node ke point korbe
//third iteration : third node nibo(value +Null),temp e second node ashbe, temp->next e third node ashbe
//4th iteration : fourth node nibo(value+null), temp e third node ashbe,  temp->next e fourth node ashbe
//ultimate ly head-> first node(temp)->(temp->next)second node(temp)->(temp->next)third node(temp)->(temp-next)fourth node
//evabe joto node shob gula interlinked hobe
// last node e temp->next e null dekhe last node will be pointing to 0

int main()
{
    int n,i;
    //n= number of nodes
    printf("Enter total nodes: ");
    scanf("%d",&n);
    //head ke null korlam jate head er value garbage na hoi
    //temp er porer node hobe new node er address
    node *head=NULL,*temp,*newnode;
   // newnode=(node*)malloc(n*sizeof(node));

    for(int i=0;i<n;i++)
    {
        newnode=(node*)malloc(sizeof(node));
        //new node er value scan korlam
        scanf("%d",&newnode->value);
        //new node er address ke Null kore nilam,
        newnode->next=NULL;
        //head jehetu apatoto Null tai head e new node er address assign
        if(head==NULL)
            head=newnode;
        //first iteration er por head Null thakbe na tokhon else kaj korbe
        else
        {
            //head e ekhon new node ase so temp e ekhon new node ashbe
            temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
        }
    }
    print(head);
}
