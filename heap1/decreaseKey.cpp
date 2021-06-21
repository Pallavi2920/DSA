// Heap Decrease
//   Given an array containing N integers, your task is:
//
//     1.To create min-heap with 1 based indexing (Insert elements one by one).
//     2.Remove the element present at index k from the heap created in the first step using Decrease key method.
//     3.Print the updated heap after second step.
//
//     Sample Input
//     2
//     5 2
//     3 2 4 1 5
//     4 2
//     4 2 3 4
//
//     Sample Output
//     1 3 4 5
//     2 4 3
#include<bits/stdc++.h>
using namespace std;
int size =0;
int parent(int i)
{
    int p = i/2;
    return p;
}
void heapifyUp(int heap[], int ele, int i)
{
    heap[i] = ele;
    while(i!=1 && heap[i]<heap[parent(i)])
    {
        swap(heap[parent(i)],heap[i]);
        i = parent(i);
    }
}
void heapifyDown(int heap[], int n, int i)
{
    int l = 2*i;
    int r = 2*i+1;
    int s = i;
    if(l<=n && heap[l]<heap[i])  s=l;
    if(r<=n && heap[r]<heap[s])  s=r;
    if(s!=i)
    {
        swap(heap[i],heap[s]);
        heapifyDown(heap,n,s);
    }
}

void replace(int heap[], int n, int k)
{
    heapifyUp(heap,-1,k);
}
void remove(int heap[])
{
    heap[1] = heap[size];
    size--;
    heapifyDown(heap,size,1);
}
void printHeap(int heap[])
{
    for(int i=1;i<=size;i++)
    {
        cout<<heap[i]<<" ";
    }
    cout<<"\n";
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int heap[n],ele;
        size =0 ;
        for(int i = 1; i<=n;i++)
        {
            size++;
            cin>>ele;
            heapifyUp(heap,ele,i);
        }
        replace(heap,n,k);
        remove(heap);
        printHeap(heap);
    }
}
