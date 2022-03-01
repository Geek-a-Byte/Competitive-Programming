Live Demo
#include <stdio.h>
#include <stdlib.h>

struct node {
   int data;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;
struct node *prev = NULL;

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

void display() {
   struct node *ptr = head;

   printf("head] =>");
   //start from the beginning
   while(ptr != NULL) {        
      printf(" %d =>",ptr->data);
      ptr = ptr->next;
   }

   printf(" [null]\n");
}

void remove_data(int data) {
   int pos = 0;
   
   if(head==NULL) {
      printf("Linked List not initialized");
      return;
   } 
    
   if(head->data == data) {
      if(head->next != NULL) {
         head = head->next;
         return;
      } else {
         head = NULL;
         printf("List is empty now");
         return;
      }
   } else if(head->data != data && head->next == NULL) {
      printf("%d not found in the list\n", data);
      return;
   }

   //prev = head;
   current = head;
   
   while(current->next != NULL && current->data != data) {
      prev = current;
      current = current->next;
   }        

   if(current->data == data) {
      prev->next = prev->next->next;
      free(current);
   } else
      printf("%d not found in the list.", data);

}

int main() {
   insert(10);
   insert(20);
   insert(30);
   insert(1);
   insert(40);
   insert(56); 

   printf("Before Removal : ");
   display();
   remove_data(30);
   printf("After Removal  : ");
   display();
   
   return 0;
}