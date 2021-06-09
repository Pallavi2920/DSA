#include<bits/stdc++.h>
using namespace std;

typedef struct Queue
{
    int front,rear;
    int capacity,size;
    int *arr;
}
Queue;
Queue *createQueue(int capacity)
{
    Queue *qu = (Queue*)malloc(sizeof(Queue));
    qu->front = 0;
    qu->size = 0;
    qu->capacity = capacity;
    qu->rear = qu->capacity-1;
    qu->arr = (int*)malloc(capacity*sizeof(int));
    return qu;
}
void enqueue(Queue *queue, int data)
{
    queue->rear = (queue->rear+1)%(queue->capacity);
    queue->arr[queue->rear] = data;
    queue->size = queue->size+1;
}
int dequeue(Queue *queue)
{
    int data;
    data = queue->arr[queue->front];
    queue->front = (queue->front+1)%(queue->capacity);
    queue->size = queue->size-1;
    return data;
}
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Queue *queue = createQueue(n);
        for(int i=1;i<=n;i++)
        {
            enqueue(queue, i);
        }
        while(queue->size!=1)
        {
            int data = dequeue(queue);
            enqueue(queue, data);
            dequeue(queue);
        }
        cout<<queue->arr[(queue->front)%(queue->capacity)]<<endl;
    }
}
