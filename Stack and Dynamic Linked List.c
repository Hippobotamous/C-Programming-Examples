#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Building a stack using a dynamic linked list
   Code can add to the stack, display elements, and remove elements
*/

typedef struct Node {
  int data;
  struct Node* next;
} Node;

int getRandomInt(int minValue, int maxValue) {
  int range = 1 + maxValue - minValue; /* Range will include max and min value */
  double normal = (rand() / (RAND_MAX + 1.0)); /* cannot divide by just RAND_MAX because we want a number strictly less than 1,
                                                   since rand() has the possibility of equaling RAND_MAX we would get 1 as a 
                                                   value for normal which would put the ending random int outside of the range */
  int result = normal * range + minValue;
  return result;
}

Node* addNode(Node* head) {
  Node* newNode = (Node*)malloc(sizeof(newNode)); /* Allocate memory for new node */
  Node* temp = head; /* Make copy of head node so we can point it at something else but still free it */
  newNode->data = getRandomInt(1, 100);
  head = newNode;
  newNode->next = temp;
  return head;
}

void displayNodes(Node* head) {
  if (head == NULL)
    printf("Stack is empty.\n");

  while (head != NULL) {
    printf("%d\n", head->data);
    head = head->next;
  }
}

Node* popNode(Node* head) {
  if (head == NULL) {
    printf("Stack is empty.\n");
    return head;
  }
  Node* temp = head;
  head = head->next;
  free(temp);
  return head;
}

int main() {
  Node* head = NULL; /* Initialize head to NULL to start linked list */
  int choice = 0; /* 1 to add a node, 2 to display list, 3 to remove node, 4 to quit */
  
  while (1) {
    printf("Enter 1 to add a node, 2 to display nodes, 3 to pop a node from the stack, or 4 to quit: ");
    scanf("%d", &choice);
    
    switch (choice) {
    case 1:
      head = addNode(head);
      break;
    case 2:
      displayNodes(head);
      break;
    case 3:
      head = popNode(head);
      break;
    case 4:
        return 0;
    }
    
  }
  return 0;
}