#include <stdio.h>
#define MAX 5
int queue[MAX];
int front =-1;
int rear=-1;
void enqueue(int value){
    if((rear +1)%MAX ==front){
        printf("queue is full.\n");
        return;
    }
    if (front==-1){
        front=0;
        rear=0;
    }else{
        rear=(rear+1)%MAX;
    }
    queue[rear]=value;
    printf("%d value inserted.\n",value);

}
void dequeue(){
    int value;
    if(front==-1){
        printf("circular queue is empty.\n");
        return;
    }
    value=queue[front];
    if (front==rear){
        front=-1;
        rear=-1;

    }else{
        front=(front+1)%MAX;
    }
    printf("%d deleted value.\n",value);

}
void display(){
    int i ;
    if (front==-1){
        printf("queue is empty.\n");
        return;
    }
    printf("circular queue:\n");
    i=front;
    while(1){
        printf("%d ",queue[i]);

        if(i==rear)
            break;

    i=(i+1)%MAX;
    }
    printf("\n");

}
int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();
    dequeue();
    display();
    dequeue();
    display();
    enqueue(60);
    display();
    enqueue(70);
    enqueue(80);
    display();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();

    return 0;
}
