/*Print the queue each time an element is inserted and deleted.
If input is
Enqueue
1
1 2
1 2 3
1 2 3 4
1 2 3 4 5

Dequeue
2 3 4 5
3 4 5
4 5
5

*/

#include<bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int data;
    Node *next;
}
Node;
typedef struct Queue
{
    Node *rear;
    Node *front;
}
Queue;
Node *createNode(int data)
{
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}
Queue *createQueue()
{
    Queue *qu = (Queue*)malloc(sizeof(Node));
    qu->front = NULL;
    qu->rear = NULL;
    return qu;
}
void enqueue(Queue *queue , int data)
{
    Node *node = createNode(data);
    if(queue->rear==NULL)
    {
        queue->front = node;
        queue->rear = node;
        return;
    }
    queue->rear->next = node;
    queue->rear = node;
}
void dequeue(Queue *queue)
{
    Node *temp = queue->front;
    queue->front = queue->front->next;
    if(queue->front == NULL)
    {
        queue->front = NULL;
        queue->rear = NULL;
    }
    free(temp);
}
void display(Queue *queue)
{
      Node *temp = queue->front;
      if(queue->front == queue->rear)
      {
          cout<<temp->data<<"\n";
      }
      else
      {
        while(temp!=NULL)
        {
              cout<<temp->data<<" ";
              temp=temp->next;
        }
        cout<<endl;
      }

}
int main()
{
    Queue *queue = createQueue();
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        enqueue(queue,arr[i]);
        display(queue);
    }
     dequeue(queue);
    for(int i=0;i<n-1;i++)
    {
        display(queue);
        dequeue(queue);
    }
}
