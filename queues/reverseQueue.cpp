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
void enqueue(Queue *queue, int data)
{
    queue->rear = (queue->rear+1)%queue->capacity;
    queue->arr[queue->rear]=data;
    queue->size = queue->size+1;
}
void reverse(Queue *queue)
{
  for(int i=0,j=queue->size-1;i<queue->size/2;i++,j--)
  {
      int temp = queue->arr[queue->front+i];
      queue->arr[queue->front+i] = queue->arr[queue->front+j];
      queue->arr[queue->front+j] = temp;
  }
}
void display(Queue *queue)
{
    for(int i=0;i<queue->size;i++)
    {
        cout<<queue->arr[(queue->front+i)%(queue->capacity)]<<" ";
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int capacity;
        cin>>capacity;
        Queue *queue = createQueue(capacity);
        for(int i=0;i<capacity;i++)
        {
            int temp;
            cin>>temp;
            enqueue(queue,temp);
        }
        reverse(queue);
        display(queue);
        cout<<"\n";
    }
}
