#include<bits/stdc++.h>
using namespace std;

typedef struct Queue
{
    int front,rear;
    int capacity,size;
    int *arr;
}Queue;

Queue *createQueue(int capacity)
{
    Queue *que = (Queue*)malloc(sizeof(Queue));
    que->capacity=capacity;
    que->size=0;
    que->front=0;
    que->rear=capacity-1;
    que->arr= (int*)malloc(que->capacity*sizeof(int));
    return que;
}
int isFull(Queue *queue)
{
    return queue->size == queue->capacity;
}
int isEmpty(Queue *queue)
{
    return queue->size ==0;
}
void enqueue(Queue *queue, int data)
{
    if(isFull(queue))
    {
        cout<<"Queue Full";
        return;
    }
    queue->rear = (queue->rear+1)%queue->capacity;
    queue->arr[queue->rear]=data;
    queue->size = queue->size+1;
}
int Dequeue(Queue *queue)
{
    if(isEmpty(queue))
    {
        cout<<"Queue Empty"<<endl;
        return INT_MIN;
    }
    int data = queue->arr[queue->front];
    queue->front = (queue->front+1)%(queue->capacity);
    queue->size = queue->size-1;
    return data;
}
int front(Queue *queue)
{
  if(isEmpty(queue))
    return INT_MIN;
  return queue->arr[queue->front];
}
int rear(Queue *queue)
{
  if(isEmpty(queue))
    return INT_MIN;
  return queue->arr[queue->rear];
}
void display(Queue *queue)
{
    for(int i=0;i<queue->size;i++)
    {
        cout<<queue->arr[(queue->front+i)%(queue->capacity)]<<" ";
    }
    cout<<endl;
}
void menu() {
    int capacity;
    cout<<"Enter the capacity of Queue:";
    cin>>capacity;
    cout<<"\n";
    Queue *queue = createQueue(capacity);
    int input = 1;

    while (input) {
        cout<<"\n";
        cout<<"### MENU ###"<<"\n";
        cout<<"Select any option:"<<"\n";
        cout<<"1. Enqueue"<<"\n";
        cout<<"2. Dequeue"<<"\n";
        cout<<"3. Display Queue"<<"\n";
        cout<<"4. Front Element of Queue"<<"\n";
        cout<<"5. Rear Element of Queue"<<"\n";
        cout<<"#. Exit"<<"\n";

        cin>>input;
        switch (input) {
            case 1: cout<<"Enter the number of elements you want to insert to Queue: ";
                    int n;
                    cin>>n;
                    for(int i=0;i<n;i++)
                    {
                        int ele;
                        cin>>ele;
                        enqueue(queue,ele);
                    }
                    break;
            case 2: cout<<"The deleted element is :"<<Dequeue(queue); break;
            case 3: display(queue); break;
            case 4: cout<<"Front Element is : "<<front(queue); break;
            case 5: cout<<"Rear Element is:"<<rear(queue); break;
            default: exit(0); break;
        }
    }

    return;
}


int main() {
  menu();
}
