#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

struct node {
   int data;
   struct node *prev;
   struct node *next;
};

struct node *list = NULL;
struct node *list_last = NULL;

struct node *even = NULL;
struct node *even_last = NULL;

struct node *odd = NULL;
struct node *odd_last = NULL;

struct node *current = NULL;

//Create Linked List
void insert(int data) {
   // Allocate memory for new node;
   struct node *link = (struct node*) malloc(sizeof(struct node));

   link->data = data;
   link->prev = NULL;
   link->next = NULL;

   // If head is empty, create new list
   if(list == NULL) {
      list = link;
      return;
   }

   current = list;

   // move to the end of the list
   while(current->next!=NULL)
      current = current->next;

   // Insert link at the end of the list
   current->next = link;
   list_last = link;
   link->prev = current;
}

//display the list
void print_backward(struct node *head) {
   struct node *ptr = head;

   printf("\n[last] <=>");
   //start from the beginning
   while(ptr != NULL) {        
      printf(" %d <=>",ptr->data);
      ptr = ptr->prev;
   }

   printf(" [head]\n");
}

//display the list
void printList(struct node *head) {
   struct node *ptr = head;

   printf("\n[head] <=>");
   //start from the beginning
   while(ptr != NULL) {        
      printf(" %d <=>",ptr->data);
      ptr = ptr->next;
   }

   printf(" [last]\n");
}

void split_list() {

   // Allocate memory for new node;
   struct node *listp;
   struct node *link;
   struct node *current;
   
   listp = list;

   while(listp->next != NULL) {
      struct node *link = (struct node*) malloc(sizeof(struct node));

      link->data = listp->data;
      link->prev = NULL;
      link->next = NULL;

      if(listp->data%2 == 0) {
         if(even == NULL) {
            even = link;
            even_last = link;
            listp = listp->next;
            continue;
         } else {
            current = even;
            while(current->next != NULL) {
               current = current->next;
            }

            // Insert link at the end of the list
            current->next = link; 
            even_last = link;
            link->prev = current;
            listp = listp->next;
         }
      } else {
         if(odd == NULL) {
            odd = link;
            odd_last = link;
            listp = listp->next;
            continue;
         } else {
            current = odd;

            while(current->next!= NULL) {
               current = current->next;
            }
            
            // Insert link at the end of the list
            current->next = link; 
            odd_last = link;
            link->prev = current;
            listp = listp->next;
         }
      }
   }
   
   // Lets handle the last node
   if(listp!=NULL) {
      link = (struct node*) malloc(sizeof(struct node));

      link->data = listp->data;
      link->prev = NULL;
      link->next = NULL;
        
      if(listp->data%2 == 0) {
         current = even;

         while(current->next != NULL) {
            current = current->next;
         }

         // Insert link at the end of the list
         current->next = link; 
         even_last = link;
         link->prev = current;
      } else {
         current = odd;

         while(current->next!= NULL) {
            current = current->next;
         }
         
         // Insert link at the end of the list
         current->next = link; 
         odd_last = link;
         link->prev = current;
      }

   }
}

int main() {
   int i;

   for(i = 1; i <= 10; i++)
      insert(i);

   printf("Complete List : ");
   printList(list);

   printf("List in reverse: ");
   print_backward(list_last);

   split_list();
   
   printf("\nAfter splitting list - \n");

   printf("Even : ");
   printList(even);

   printf("Odd  : ");
   printList(odd);
   
   printf("\nSplitted lists in reverse - \n");
   
   printf("Even : ");
   print_backward(even_last);
   
   printf("Odd  : ");
   print_backward(odd_last);
   
   return 0;
}