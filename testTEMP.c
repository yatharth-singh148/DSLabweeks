#include <stdio.h>
#include <stdlib.h>

struct Node {
   int data;
   struct Node* next;
};

void insertAtBeginning(struct Node** head, int ndata) {
   struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // allocation of memory
   newNode->data = ndata;
   newNode->next = *head;
   *head = newNode;
}

void insertAtEnd(struct Node** head, int newData) {
   struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = newData;
   newNode->next = NULL;

   if (*head == NULL) {
      *head = newNode;
      return;
   }

   struct Node* temp = *head;
   while (temp->next != NULL) {
      temp = temp->next;
   }

   temp->next = newNode;
}

void insertAfterPosition(struct Node** head, int pos, int newData) {
   struct Node* temp = *head;
   int count = 1;

   while (temp != NULL && count < pos) {
      temp = temp->next;
      count++;
   }

   if (temp == NULL) {
      printf("Position out of bounds.\n");
      return;
   }

   struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = newData;
   newNode->next = temp->next;
   temp->next = newNode;
}

void insertAfterValue(struct Node** head, int value, int newData) {
   struct Node* temp = *head;

   while (temp != NULL && temp->data != value) {
      temp = temp->next;
   }

   if (temp == NULL) {
      printf("Value not found in the list.\n");
      return;
   }

   struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = newData;
   newNode->next = temp->next;
   temp->next = newNode;
}

void display(struct Node* head) {
   struct Node* temp = head;
   while (temp != NULL) {
      printf("%d -> ", temp->data);
      temp = temp->next;
   }
   printf("NULL\n");
}

void deleteFromFront(struct Node** head) {
   if (*head == NULL) {
      printf("List is empty.\n");
      return;
   }
   struct Node* temp = *head;
   *head = (*head)->next;
   free(temp);
}

void deleteFromBack(struct Node** head) {
   if (*head == NULL) {
      printf("List is empty.\n");
      return;
   }
   if ((*head)->next == NULL) {
      printf("Free %d\n", (*head)->data);
      free(*head);
      *head = NULL;
      return;
   }
   struct Node* temp = *head;
   while (temp->next->next != NULL) {
      temp = temp->next;
   }
   free(temp->next);
   temp->next = NULL;
}

void main() {
   int ch, d, pos, ref;
   struct Node* head = NULL;
   while (1) {
      printf("\n-----[~ LINKED LIST OPERATIONS ~]-----");
      printf("\n1 -> Insert from front\n2 -> Display\n3 -> Delete from front\n4 -> Insert at end\n5 -> Insert after position\n6 -> Insert after value\n0 -> Exit");
      printf("\nEnter your choice:\n");
      scanf("%d", &ch);
      switch (ch) {
         case 1:
            printf("Enter element to be inserted: ");
            scanf("%d", &d);
            insertAtBeginning(&head, d);
            break;
         case 2:
            display(head);
            break;
         case 3:
            deleteFromFront(&head);
            break;
         case 4:
            printf("Enter element to be inserted: ");
            scanf("%d", &d);
            insertAtEnd(&head, d);
            break;
         case 5:
            printf("Enter position to insert after: ");
            scanf("%d", &pos);
            printf("Enter element to be inserted: ");
            scanf("%d", &d);
            insertAfterPosition(&head, pos, d);
            break;
         case 6:
            printf("Enter value to insert after: ");
            scanf("%d", &ref);
            printf("Enter element to be inserted: ");
            scanf("%d", &d);
            insertAfterValue(&head, ref, d);
            break;
         case 0:
            exit(0);
            break;
         default:
            printf("\nEnter valid option!\n");
      }
   }
}
