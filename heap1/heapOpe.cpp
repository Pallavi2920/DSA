#include<bits/stdc++.h>
using namespace std;
int size=0;
void heapifyDown(int heap[],int n,int i)
{
    int l  = 2*i+1;
    int r = 2*i+2;
    int s = i;
    if(l<n && heap[l]<heap[i])  s=l;
    if(r<n && heap[r]<heap[s])  s=r;
    if(s!=i)
    {
        swap(heap[i],heap[s]);
        heapifyDown(heap,n,s);
    }
}
void printHeap(int heap[])
{
    for(int i = 0; i<size;i++)
    {
        cout<<heap[i]<<" ";
    }
    cout<<endl;
}
void extractMin(int heap[])
{
    int root = heap[0];
    heap[0]=heap[size-1];
    size--;
    heapifyDown(heap,size,0);
    cout<<root<<" ";
    // printHeap(heap);
}

int parent(int i)
{
    int p = (i-1)/2;
    return p;
}
void insert(int heap[],int ele,int i)
{
    heap[i]=ele;
    while(i!=0 && heap[i]<heap[parent(i)])
    {
        swap(heap[i],heap[parent(i)]);
        i = parent(i);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        size=0;
        int n;
        cin>>n;
        int heap[n];
        int ele;
        for(int i = 0; i<n;i++)
        {
              cin>>ele;
              insert(heap,ele,i);
              size++;
        }
        extractMin(heap);
        printHeap(heap);
    }
}
