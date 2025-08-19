#include<stdio.h>
#define MAX 10

int queue[MAX];
int front = -1 , rear = -1;

void enqueue(int num);
int dequeue();
int peek();
void display();

int main()
{
    int option, val;
    while(option != 5)
    {
        printf("\n\n ***** MAIN MENU *****");
        printf("\n 1. Enqueue");
        printf("\n 2. dequeue");
        printf("\n 3. peek");
        printf("\n 4. display the queue");
        printf("\n 5. EXIT");
        printf("\n 6. enter your opinion");
        scanf("%d", &option);

        switch(option)
        {
        case 1 :
            printf("\n enter the number to be inserted in the queue");
            scanf("%d", &val);
            enqueue(val);
            break;
        case 2 :
            val = dequeue();
            if (front != -1 || front < rear )
                printf("\n the number deleted is : %d " , val );
            break;
        case 3 :
            val = peek();
            if ( front != -1 || front < rear )
                printf("\n the first value in queue is : %d " , val);
            break;
        case 4 :
            display();
            break;
        }
    }
    return 0;
}

void enqueue(int num)
{
    if ( rear == MAX -1 )
        printf("\n OVERFLOW");
    else if (front == -1 && rear == -1 )
    {
        front = 0;
        rear = 0;
        queue[rear] = num;
    }
    else
    {
        rear++;
        queue[rear] = num;
    }
}

int dequeue()
{
    int val;
    if (front == -1 || front > rear )
    {
        printf("\n UNDERFLOW");
        return -1;
    }
    else {
        val = queue[front];
        front++;
        if ( front> rear )
        {
            front = -1;
            rear = -1;
        }
        return val;
    }
}

int peek()
{
    if(front == -1 || front > rear)
    {
        printf("\n QUEUE IS EMPTY");
        return -1;
    }
    else{
        return queue[front];
    }
}

void display()
{
    int i;
    printf("\n");
    if (front == -1 || front > rear )
        printf("\n QUEUE IS EMPTY");
    else
    {
        for( i = front ; i<= rear ; i++)
            printf("\t %d ", queue[i]);
    }
}


//circular queue

#include <stdio.h>
#define MAX 10

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int num);
int dequeue();
int peek();
void display();

int main() {
    int option = 0, val;
    while(option != 5) {
        printf("\n\n ***** MAIN MENU *****");
        printf("\n 1. Enqueue");
        printf("\n 2. Dequeue");
        printf("\n 3. Peek");
        printf("\n 4. Display the queue");
        printf("\n 5. EXIT");
        printf("\n Enter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("\n Enter the number to be inserted in the queue: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                val = dequeue();
                if(front != -1)
                    printf("\n The number deleted is: %d", val);
                break;
            case 3:
                val = peek();
                if(front != -1)
                    printf("\n The first value in queue is: %d", val);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("\n Exiting...");
                break;
            default:
                printf("\n Invalid option! Try again.");
        }
    }
    return 0;
}

void enqueue(int num) {
    if ((rear+1)%MAX==front)
        printf("\n OVERFLOW");
    else if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
        queue[rear] = num;
    }
    else if(rear == MAX-1 && front !=0)
    {
        rear=0;
        queue[rear]= num;
    }
    else {
        rear++;
        queue[rear] = num;
    }
}

int dequeue() {
    int val;
    if (front == -1) {
        printf("\n UNDERFLOW");
        return -1;
    } else {
        val = queue[front];
        if(front == rear)
        {
            front = -1;
            rear = -1;
        }
       else
       {
           if(front == MAX-1)
            front=0;
           else
            front++;
       }

        return val;
    }
}

int peek() {
    if (front == -1) {
        printf("\n QUEUE IS EMPTY");
        return -1;
    } else {
        return queue[front];
    }
}

void display() {
    int i;
    printf("\n");
    if (front == -1 && rear == -1)
        printf("\n QUEUE IS EMPTY");
    else
    {
        if(front<=rear)
        {
            for(i=front ; i<=rear ; i++)
                printf("\t %d" , queue[i]);
        }
        else
        {
            for(i=front; i<MAX; i++)
                printf("\t %d ", queue[i]);
            for(i=0; i<=rear ;i++)
                printf("\t %d", queue[i]);
        }
    }
}
