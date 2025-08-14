
#include <stdio.h>
#include <stdlib.h>

// This struct represents ONE node in the linked list
typedef struct Node {
    int data;           
    struct Node* next;  
} Node;


Node* head = NULL;

// Function prototypes
void insertAtStart();
void insertAtEnd();
void insertAfterPosition();
void deleteFromStart();
void deleteFromPosition();
void deleteByValue();
void printList();
int getLength();
void reverseList();

int main() {
    int choice;

    while (1) {
        // Menu of actions you can perform on the linked list
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert at start\n");
        printf("2. Insert at end\n");
        printf("3. Insert after position\n");
        printf("4. Delete from start\n");
        printf("5. Delete from position\n");
        printf("6. Delete by value\n");
        printf("7. Print list\n");
        printf("8. Get length\n");
        printf("9. Reverse list\n");
        printf("10. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertAtStart(); break;
            case 2: insertAtEnd(); break;
            case 3: insertAfterPosition(); break;
            case 4: deleteFromStart(); break;
            case 5: deleteFromPosition(); break;
            case 6: deleteByValue(); break;
            case 7: printList(); break;
            case 8: printf("List length: %d\n", getLength()); break;
            case 9: reverseList(); break;
            case 10: exit(0);
            default: printf("Invalid choice, try again.\n");
        }
    }
}

// Put a new node at the very start of the list
void insertAtStart() {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &newNode->data);

   
    newNode->next = head;

   
    head = newNode;
    printf("Inserted at start.\n");
}


void insertAtEnd() {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    if (head == NULL) {
        
        head = newNode;
    } else {
        
        
        while (temp->next != NULL)
            temp = temp->next;
       
        temp->next = newNode;
    }
    printf("Inserted at end.\n");
}


void insertAfterPosition() {
    int pos, count = 1;
    printf("Insert after position: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > getLength()) {
        printf("Position out of range!\n");
        return;
    }

    Node* temp = head;
    while (count < pos) {
        temp = temp->next;
        count++;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &newNode->data);

   
    newNode->next = temp->next;
  
    temp->next = newNode;
    printf("Inserted after position %d.\n", pos);
}


void deleteFromStart() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node* temp = head;
    head = head->next; 
    printf("Deleted value: %d\n", temp->data);
    free(temp);
}

 //Delete a node at a specific position
void deleteFromPosition() {
    int pos, count = 1;
    printf("Delete node at position: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > getLength()) {
        printf("Invalid position!\n");
        return;
    }

    if (pos == 1) {
        deleteFromStart();
        return;
    }

    Node* temp = head;
    while (count < pos - 1) {
        temp = temp->next;
        count++;
    }

    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    printf("Deleted value: %d\n", toDelete->data);
    free(toDelete);
}

// Delete the first node with a given value

void deleteByValue() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    int value;
    printf("Enter value to delete: ");
    scanf("%d", &value);

   
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        free(temp);
        printf("Deleted value: %d\n", value);
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->data != value)
        temp = temp->next;

    if (temp->next == NULL) {
        printf("Value not found!\n");
        return;
    }

    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
    printf("Deleted value: %d\n", value);
}


void printList() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int getLength() {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Reverse the order of the list
void reverseList() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) {
       
        next = current->next;
        
        current->next = prev;
        
        prev = current;
        current = next;
    }
    head = prev; 
    printf("List reversed!\n");
}
