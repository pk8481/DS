#include <stdio.h>
#define MAX 5

int queue[MAX];
int priority[MAX];
int size = 0;

void insert(int value, int p)
{
    if (size == MAX)
    {
        printf("Priority Queue Overflow\n");
        return;
    }

    queue[size] = value;
    priority[size] = p;
    size++;

    printf("%d inserted with priority %d\n", value, p);
}

void deleteElement()
{
    int i;
    int highest;
    int value;

    if (size == 0)
    {
        printf("Priority Queue Underflow\n");
        return;
    }

    highest = 0;

    for (i = 1; i < size; i++)
    {
        if (priority[i] < priority[highest])
        {
            highest = i;
        }
    }

    value = queue[highest];

    for (i = highest; i < size - 1; i++)
    {
        queue[i] = queue[i + 1];
        priority[i] = priority[i + 1];
    }

    size--;

    printf("%d deleted from priority queue\n", value);
}

void display()
{
    int i;

    if (size == 0)
    {
        printf("Priority Queue is empty\n");
        return;
    }

    printf("Element\tPriority\n");

    for (i = 0; i < size; i++)
    {
        printf("%d\t%d\n", queue[i], priority[i]);
    }
}

int main()
{
    insert(10, 3);
    insert(20, 1);
    insert(30, 2);

    printf("\nPriority Queue:\n");
    display();

    printf("\nDeleting highest-priority element:\n");
    deleteElement();

    printf("\nPriority Queue after deletion:\n");
    display();

    return 0;
}
