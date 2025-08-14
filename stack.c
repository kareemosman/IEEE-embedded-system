#include <stdio.h>
#include <stdlib.h>

int stack[100], choice, n, top, x, i;
void push(void);
void pop(void);
void display(void);
void peek(void); 

int main()
{
    top = -1;
    printf("\n Enter the size of STACK[MAX=100]: ");
    scanf("%d", &n);
    printf("\n\t STACK OPERATIONS USING ARRAY");
    printf("\n\t--------------------------------");
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.PEEK\n\t 5.EXIT");

    do
    {
        printf("\n Enter the Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        case 5:
            printf("\n\t EXIT ");
            break;
        default:
            printf("\n\t Please Enter a Valid Choice(1/2/3/4/5)");
        }
    } while (choice != 5);

    return 0;
}

void push()
{
    if (top >= n - 1)
    {
        printf("\n\tSTACK is over flow");
    }
    else
    {
        printf(" Enter a value to be pushed: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
}

void pop()
{
    if (top <= -1)
    {
        printf("\n\t Stack is under flow");
    }
    else
    {
        printf("\n\t The popped element is %d", stack[top]);
        top--;
    }
}

void display()
{
    if (top >= 0)
    {
        printf("\n The elements in STACK \n");
        for (i = top; i >= 0; i--)
            printf("\n%d", stack[i]);
        printf("\n Press Next Choice");
    }
    else
    {
        printf("\n The STACK is empty");
    }
}

void peek()
{
    if (top >= 0)
    {
        printf("\n The top element is: %d", stack[top]);
    }
    else
    {
        printf("\n The STACK is empty");
    }
}

//Implementation of Infix-to-Postfix and Postfix-to-Infix Conversions


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

typedef struct {
    char items[SIZE];
    int top;
} CharStack;

void initCharStack(CharStack *s) {
    s->top = -1;
}

int isCharEmpty(CharStack *s) {
    return s->top == -1;
}

int isCharFull(CharStack *s) {
    return s->top == SIZE - 1;
}

void pushChar(CharStack *s, char c) {
    if (!isCharFull(s)) {
        s->items[++s->top] = c;
    }
}

char popChar(CharStack *s) {
    if (!isCharEmpty(s)) {
        return s->items[s->top--];
    }
    return '\0';
}

char peekChar(CharStack *s) {
    if (!isCharEmpty(s)) {
        return s->items[s->top];
    }
    return '\0';
}

int precedenceOf(char op) {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

int isOp(char c) {
    return (c == '+'  c == '-'  c == '*'  c == '/'  c == '^');
}

// ===== Stack for strings (operands in postfix to infix) =====
typedef struct {
    char items[SIZE][SIZE];
    int top;
} StringStack;

void initStringStack(StringStack *s) {
    s->top = -1;
}

void pushString(StringStack *s, const char *str) {
    strcpy(s->items[++s->top], str);
}

char* popString(StringStack *s) {
    return s->items[s->top--];
}

// ===== Infix to Postfix =====
void convertInfixToPostfix(char *infix, char *postfix) {
    CharStack s;
    initCharStack(&s);
    int i, k = 0;
    char c;

    for (i = 0; i < strlen(infix); i++) {
        c = infix[i];

        if (isalnum(c)) { // Operand
            postfix[k++] = c;
        }
        else if (c == '(') {
            pushChar(&s, c);
        }
        else if (c == ')') {
            while (!isCharEmpty(&s) && peekChar(&s) != '(') {
                postfix[k++] = popChar(&s);
            }
            popChar(&s); // Remove '('
        }
        else if (isOp(c)) {
            while (!isCharEmpty(&s) && precedenceOf(peekChar(&s)) >= precedenceOf(c)) {
                postfix[k++] = popChar(&s);
            }
            pushChar(&s, c);
        }
    }
    while (!isCharEmpty(&s)) {
        postfix[k++] = popChar(&s);
    }
    postfix[k] = '\0';
}

// ===== Postfix to Infix =====
void convertPostfixToInfix(char *postfix, char *infix) {
    StringStack s;
    initStringStack(&s);
    char c;
    int i;

    for (i = 0; i < strlen(postfix); i++) {
        c = postfix[i];

        if (isalnum(c)) {
            char temp[2] = {c, '\0'};
            pushString(&s, temp);
        }
        else if (isOp(c)) {
            char op2[SIZE], op1[SIZE], expr[SIZE];
            strcpy(op2, popString(&s));
            strcpy(op1, popString(&s));
            sprintf(expr, "(%s%c%s)", op1, c, op2);
            pushString(&s, expr);
        }
    }
    strcpy(infix, popString(&s));
}

// ===== Main Menu =====
int main() {
    char infixExp[SIZE], postfixExp[SIZE], result[SIZE];
    int choice;

    do {
        printf("\n=== Conversion Menu ===\n");
        printf("1. Infix to Postfix\n");
        printf("2. Postfix to Infix\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Infix expression: ");
                scanf("%s", infixExp);
                convertInfixToPostfix(infixExp, postfixExp);
                printf("Postfix: %s\n", postfixExp);
                break;

            case 2:
                printf("Enter Postfix expression: ");
                scanf("%s", postfixExp);
                convertPostfixToInfix(postfixExp, result);
                printf("Infix: %s\n", result);
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);

    return 0;
}