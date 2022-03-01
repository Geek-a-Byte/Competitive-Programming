Live Demo
#include <stdio.h>
#include <stdlib.h>

struct node {
   int data;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

//Create Linked List
void insert(int data) {
   // Allocate memory for new node;
   struct node *link = (struct node*) malloc(sizeof(struct node));

   link->data = data;
   link->next = NULL;

   // If head is empty, create new list
   if(head==NULL) {
      head = link;
      return;
   }

   current = head;
   
   // move to the end of the list
   while(current->next!=NULL)
      current = current->next;
   
   // Insert link at the end of the list
   current->next = link; 
}

void size_of_list() {
   int size = 0;
   
   if(head==NULL) {
      printf("List size : %d ", size);
      return;
   } 

   current = head;
   size = 1;
   while(current->next!=NULL) {
      current = current->next;
      size++;
   }
   printf("List size : %d ", size);
}

int main() {
   insert(10);
   insert(20);
   insert(30);
   insert(1);
   insert(40);
   insert(56); 

   size_of_list();
   return 0;
}