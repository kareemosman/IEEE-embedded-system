#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// ================== Structures ==================
typedef struct {
    char holder[50];
    char PAN[20];
    int expMonth;
    int expYear;
    double balance;
    double maxLimit;
    bool isValid;
} Account;

typedef struct {
    char PAN[20];
    double amount;
    bool status; // Approved or Declined
} Transaction;

// ================== Array Stack ==================
#define MAX 100
Transaction arrayStack[MAX];
int topArr = -1;

void pushArray(Transaction t) {
    if (topArr < MAX - 1) {
        arrayStack[++topArr] = t;
    }
}
Transaction popArray() {
    Transaction t = {"", 0, false};
    if (topArr >= 0) {
        t = arrayStack[topArr--];
    }
    return t;
}
void displayArrayStack() {
    printf("\n=== Transaction History (Array Stack) ===\n");
    for (int i = topArr; i >= 0; i--) {
        printf("PAN: %s | Amount: %.2f | Status: %s\n",
               arrayStack[i].PAN,
               arrayStack[i].amount,
               arrayStack[i].status ? "Approved" : "Declined");
    }
}

// ================== Linked List Stack ==================
typedef struct Node {
    Transaction txn;
    struct Node* next;
} Node;

Node* top = NULL;

void pushLinked(Transaction t) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->txn = t;
    newNode->next = top;
    top = newNode;
}
Transaction popLinked() {
    Transaction t = {"", 0, false};
    if (top != NULL) {
        Node* temp = top;
        t = temp->txn;
        top = top->next;
        free(temp);
    }
    return t;
}
void displayLinkedStack() {
    Node* temp = top;
    printf("\n=== Transaction History (Linked List Stack) ===\n");
    while (temp != NULL) {
        printf("PAN: %s | Amount: %.2f | Status: %s\n",
               temp->txn.PAN,
               temp->txn.amount,
               temp->txn.status ? "Approved" : "Declined");
        temp = temp->next;
    }
}

// ================== Queue (Pending Transactions) ==================
typedef struct QNode {
    Transaction txn;
    struct QNode* next;
} QNode;

QNode* front = NULL;
QNode* rear = NULL;

void enqueue(Transaction t) {
    QNode* newNode = (QNode*)malloc(sizeof(QNode));
    newNode->txn = t;
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}
Transaction dequeue() {
    Transaction t = {"", 0, false};
    if (front != NULL) {
        QNode* temp = front;
        t = temp->txn;
        front = front->next;
        if (front == NULL) rear = NULL;
        free(temp);
    }
    return t;
}
void displayQueue() {
    QNode* temp = front;
    printf("\n=== Pending Transactions (Queue) ===\n");
    while (temp != NULL) {
        printf("PAN: %s | Amount: %.2f | Status: %s\n",
               temp->txn.PAN,
               temp->txn.amount,
               temp->txn.status ? "Approved" : "Declined");
        temp = temp->next;
    }
}

// ================== Main ==================
int main() {
    Account acc;
    int cm, cy;
    Transaction t;

    // ------- Step by step inputs -------
    printf("Enter the holder name:\n");
    scanf(" %[^\n]", acc.holder);

    printf("\nEnter the PAN (16 digits):\n");
    scanf(" %[^\n]", acc.PAN);

    printf("\nEnter the expiration year (YYYY):\n");
    scanf("%d", &acc.expYear);

    printf("\nEnter the expiration month (MM):\n");
    scanf("%d", &acc.expMonth);

    printf("\nEnter the current month (MM):\n");
    scanf("%d", &cm);

    printf("\nEnter the current year (YYYY):\n");
    scanf("%d", &cy);

    // ------- Setup dummy account -------
    acc.balance = 1000;
    acc.maxLimit = 2000;
    acc.isValid = true;

    // ------- Validate card expiry -------
    if (acc.expYear < cy || (acc.expYear == cy && acc.expMonth < cm)) {
        printf("\nDeclined: Card expired\n");
        return 0;
    }

    // ------- Show account info -------
    printf("\nAccount Information:\n");
    printf("PAN: %s\n", acc.PAN);
    printf("Balance: %.2f\n", acc.balance);
    printf("Max Payment Limit: %.2f\n", acc.maxLimit);
    printf("Account Status: %s\n", acc.isValid ? "Valid" : "Invalid");

    // ------- Transaction -------
    printf("\nEnter transaction amount:\n");
    scanf("%lf", &t.amount);
    strcpy(t.PAN, acc.PAN);

    if (t.amount > acc.balance) {
        printf("\nDeclined: Insufficient balance\n");
        t.status = false;
        enqueue(t);
    } else if (t.amount > acc.maxLimit) {
        printf("\nDeclined: Amount exceeds limit\n");
        t.status = false;
        enqueue(t);
    } else {
        double prevBalance = acc.balance;
        acc.balance -= t.amount;
        t.status = true;

        printf("\nBalance updated successfully. New balance: %.2f\n", acc.balance);
        printf("Transaction Approved\n");

        // ------- Receipt -------
        printf("\n========== TRANSACTION RECEIPT ==========\n");
        printf("Card Holder: %s\n", acc.holder);
        printf("PAN: %s\n", acc.PAN);
        printf("Transaction Amount: $%.2f\n", t.amount);
        printf("----------------------------------------\n");
        printf("Previous Balance: $%.2f\n", prevBalance);
        printf("New Balance: $%.2f\n", acc.balance);
        printf("Max Payment Limit: $%.2f\n", acc.maxLimit);
        printf("----------------------------------------\n");
        printf("Status: %s\n", t.status ? "APPROVED" : "DECLINED");

        time_t now = time(NULL);
        printf("Date: %s", ctime(&now));
        printf("========================================\n");
    }

    // push to both stacks
    pushArray(t);
    pushLinked(t);

    // show history + queue
    displayArrayStack();
    displayLinkedStack();
    displayQueue();

    // ------- Undo -------
    char ch;
    printf("\nDo you want to undo last transaction? (y/n):\n");
    scanf(" %c", &ch);

    if (ch == 'y' || ch == 'Y') {
        Transaction undoneA = popArray();
        Transaction undoneL = popLinked();
        if (undoneA.status) {
            acc.balance += undoneA.amount;
            printf("\nArrayStack Undo: PAN=%s, Amount=%.2f\n", undoneA.PAN, undoneA.amount);
        }
        if (undoneL.status) {
            printf("LinkedStack Undo: PAN=%s, Amount=%.2f\n", undoneL.PAN, undoneL.amount);
        }
    }

    // Final account info
    printf("\nAccount Information:\n");
    printf("PAN: %s\n", acc.PAN);
    printf("Balance: %.2f\n", acc.balance);
    printf("Max Payment Limit: %.2f\n", acc.maxLimit);
    printf("Account Status: %s\n", acc.isValid ? "Valid" : "Invalid");

    return 0;
}
// ===========OUTPUT====================
Enter the holder name:
karim

Enter the PAN (16 digits):
1111222233334444

Enter the expiration year (YYYY):
2026

Enter the expiration month (MM):
12

Enter the current month (MM):
11

Enter the current year (YYYY):
2025

Account Information:
PAN: 1111222233334444
Balance: 1000.00
Max Payment Limit: 2000.00
Account Status: Valid

Enter transaction amount:
1000

Balance updated successfully. New balance: 0.00
Transaction Approved

========== TRANSACTION RECEIPT ==========
Card Holder: karim
PAN: 1111222233334444
Transaction Amount: $1000.00
----------------------------------------
Previous Balance: $1000.00
New Balance: $0.00
Max Payment Limit: $2000.00
----------------------------------------
Status: APPROVED
Date: Sun Aug 31 05:55:07 2025
========================================

=== Transaction History (Array Stack) ===
PAN: 1111222233334444 | Amount: 1000.00 | Status: Approved

=== Transaction History (Linked List Stack) ===
PAN: 1111222233334444 | Amount: 1000.00 | Status: Approved

=== Pending Transactions (Queue) ===

Do you want to undo last transaction? (y/n):
n

Account Information:
PAN: 1111222233334444
Balance: 0.00
Max Payment Limit: 2000.00
Account Status: Valid

Process returned 0 (0x0)   execution time : 88.825 s
Press any key to continue.













































































































































































