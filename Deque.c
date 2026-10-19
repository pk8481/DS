#include <stdio.h>
#define MAX 5

int deque[MAX];
int front = -1;
int rear = -1;

void insertFront(int value)
{
    if ((front == 0 && rear == MAX - 1) ||
        (front == rear + 1))
    {
        printf("Deque Overflow\n");
        return;
    }

    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (front == 0)
    {
        front = MAX - 1;
    }
    else
    {
        front--;
    }

    deque[front] = value;
    printf("%d inserted at front\n", value);
}

void insertRear(int value)
{
    if ((front == 0 && rear == MAX - 1) ||
        (front == rear + 1))
    {
        printf("Deque Overflow\n");
        return;
    }

    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (rear == MAX - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }

    deque[rear] = value;
    printf("%d inserted at rear\n", value);
}

void deleteFront()
{
    int value;

    if (front == -1)
    {
        printf("Deque Underflow\n");
        return;
    }

    value = deque[front];

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == MAX - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }

    printf("%d deleted from front\n", value);
}

void deleteRear()
{
    int value;

    if (front == -1)
    {
        printf("Deque Underflow\n");
        return;
    }

    value = deque[rear];

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
    {
        rear = MAX - 1;
    }
    else
    {
        rear--;
    }

    printf("%d deleted from rear\n", value);
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque: ");
    i = front;

    while (1)
    {
        printf("%d ", deque[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main()
{
    insertRear(10);
    insertRear(20);
    insertRear(30);
    display();

    insertFront(5);
    display();

    deleteFront();
    display();

    deleteRear();
    display();

    return 0;
}
