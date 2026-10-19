#include <stdio.h>
#define MAX 5
int queue[MAX];
int front = -1;
int rear = -1;
// Function to insert an element
void enqueue(int value)
{
// Check whether queue is full

if (rear == MAX - 1)
{
printf("Queue Overflow\n");
return;
}
// If this is the first element
if (front == -1)
{
front = 0;
}
// Increase rear and insert element
rear++;
queue[rear] = value;
printf("%d inserted into queue\n", value);
}
// Function to delete an element
void dequeue()
{
int value;
// Check whether queue is empty
if (front == -1 || front > rear)
{
printf("Queue Underflow\n");
return;
}
// Store the element to be deleted
value = queue[front];
// Move front to next element
front++;
printf("%d deleted from queue\n", value);
}
// Function to display queue
void display()
{
int i;
if (front == -1 || front > rear)
{
printf("Queue is empty\n");
return;
}
printf("Queue: ");
for (i = front; i <= rear; i++)
{
printf("%d ", queue[i]);
}
printf("\n");
}

int main()
{
enqueue(10);
enqueue(20);
enqueue(30);
display();
dequeue();
display();
return 0;
}