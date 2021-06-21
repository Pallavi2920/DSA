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
void heapifyUp(int heap[],int i,int ele)
{
    heap[i] = ele;
    while(i!=1 && heap[i]<heap[i/2])
    {
        swap(heap[i],heap[i/2]);
        i = i/2;
    }
}
void decreaseKey(int heap[],int k)
{
        heap[k] = heap[n]
        heapifyUp(heap,k,heap[k]);
}
void printHeap(int heap[],int n)
{
    for(int i = 1; i<=n;i++)
    {
        cout<<heap[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int heap[n];
        int ele;
        for(int i = 1; i<=n;i++)
        {
            cin>>ele;
            heapifyUp(heap,ele,i);
        }
        decreaseKey(heap,k);
        printHeap(heap,k);
    }
}
