#include<bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
}
Node;
typedef struct Queue
{
    Node *front;
    Node *rear;
}
Queue;
Node *createNode(int data)
{
    Node *node = (Node*)malloc(sizeof(Node));
    node->data=data;
    node->next=NULL;
    return node;
}
Queue *createQueue()
{
    Queue *qu = (Queue*)malloc(sizeof(Queue));
    qu->front=NULL;
    qu->rear=NULL;
    return qu;
}

void enqueue(Queue *queue , int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    if(queue->rear == NULL)
    {
        queue->rear = node;
        queue->front = node;
        return;
    }
    queue->rear->next = node;
    queue->rear = node;
}
int dequeue(Queue *queue)
{

    if(queue->front==NULL)
    {
        return INT_MIN;
    }
    Node *temp = queue->front;
    queue->front = queue->front->next;
    if(queue->front == queue->rear)
    {
        queue->front = NULL;
        queue->rear = NULL;
    }
    int data = temp->data;
    free(temp);
    return data;
}
void display(Queue *queue)
{
      if(queue->front==NULL && queue->rear==NULL)
      {
          cout<<"Queue Empty";
      }
      else
      {
          Node *temp = queue->front;
          cout<<"The Queue is :";
          while(temp!=NULL)
          {
              cout<<temp->data<<" ";
              temp=temp->next;
          }
          cout<<endl;
      }
}
void menu()
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
  for(int i=0;i<n;i++)
  {
      dequeue(queue);
      display(queue);
  }

  // int input = 1;
  // Queue *queue = (Queue*)malloc(sizeof(Queue));
  // while (input) {
  //     cout<<"\n";
  //     cout<<"### MENU ###"<<"\n";
  //     cout<<"Select any option:"<<"\n";
  //     cout<<"1. Enqueue"<<"\n";
  //     cout<<"2. Dequeue"<<"\n";
  //     cout<<"3. Display Queue"<<"\n";
  //     cout<<"4. Front Element of Queue"<<"\n";
  //     cout<<"5. Rear Element of Queue"<<"\n";
  //     cout<<"#. Exit"<<"\n";
  //
  //     cin>>input;
  //     switch (input) {
  //         case 1: cout<<"Enter the number of elements you want to insert to Queue: ";
  //                 int n;
  //                 cin>>n;
  //                 for(int i=0;i<n;i++)
  //                 {
  //                     int ele;
  //                     cin>>ele;
  //                     enqueue(queue,ele);
  //                 }
  //                 break;
  //         case 2: cout<<"The deleted element is :"<<dequeue(queue); break;
  //         case 3: display(queue); break;
  //         case 4: cout<<"Front Element is : "<<queue->front->data; break;
  //         case 5: cout<<"Rear Element is:"<<queue->rear->data; break;
  //         default: exit(0); break;
  //     }
  // }

  return;
}
int main()
{
    menu();
}
