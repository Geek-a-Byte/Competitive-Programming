#include<stdio.h>
#include<stdlib.h>
int *array;
int maxsize=12;
int size;
void init()
{
     array=(int*)malloc(sizeof(int)*maxsize);
     size=0;
}

int InsertAt(int val,int pos)
{
    if(size==maxsize)
    {
        maxsize=maxsize*2;
        array=(int*)realloc(array,maxsize*sizeof(int));
    }

    for(int i=size;i>pos;i--)
    {
        array[i]=array[i-1];
    }
    array[pos]=val;
    size++;
    return 1;

}

int DeleteFirst()
{
    for(int i=0;i<size;i++)
    {
        array[i]=array[i+1];

    }
    size--;
    return 1;

}
void printArray()
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",array[i]);
    }

}

int main()
{
  init();
  printf("Enter the capacity of the array:\n");
  scanf("%d",&size);
  printf("enter the elements of the array:\n");
  for(int i=0;i<size;i++)
  {
      scanf("%d",&array[i]);
  }
  printf("Enter 1 for Insertat\nEnter 2 for Deletefirst\nEnter 3 for Printarray\nEnter 4 for Quit\n");

  while(1){
        int choose;
        printf("Enter the option you want to select\n");
        scanf("%d",&choose);
  if(choose==1)
  {
        int val,pos;
        printf("enter the value and the pos:\n");
        scanf("%d%d",&val,&pos);
        //bound checking
      if(pos<size && InsertAt(val,pos))//ekhane (InsertAt(val,pos) && pos<size) deya jabe na karon eta dile oitar khetre function e size ek baraye ashbe
      {
          printf("the first element was successfully inserted\n");
      }
      else if(pos>=size)
      {
          printf("array bound exceeded, so The first element was not inserted\n");
      }

  }
  else if(choose==2)
  {
      if(DeleteFirst())
      {
          printf("The first element of the array was deleted\n");
      }
      else
      {
          printf("the first element of the array was not deleted\n");
      }


  }
  else if(choose==3)
  {
      printArray();


  }
  else if(choose!=1||choose!=2||choose!=3)
    break;
  }
  //shrink
  maxsize = size;
  array = (int*) realloc(array, maxsize*sizeof(int));
  printf("The shrinked size of the array is %d ", sizeof(array)/sizeof(int));
    free(array);
}
