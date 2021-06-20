// Given an array sort it using heap sort.
// Approach:
//     step1:  With the given array create a heap using buildHeap()/ bottom up approach.
//     step2:  After crating heap run a loop from n-1 to greater than 0 and for each iteration swap the ith element with 0th element and apply heapifyDown(heap,i,0) on root index.
#include<bits/stdc++.h>
using namespace std;
void heapifyDown(int heap[], int n, int i)
{
    int l = 2*i+1;
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
void buildHeap(int heap[], int n)
{
    for(int i = (n/2)-1; i>=0;i--)
    {
        heapifyDown(heap,n,i);
    }
}
void printHeap(int heap[], int n)
{
    for(int i=n-1;i>=0;i--)
    {
        cout<<heap[i]<<" ";
    }
    cout<<'\n';
}
void heapSort(int heap[], int n)
{
    buildHeap(heap,n);
    for(int i = n-1; i>0;i--)
    {
        swap(heap[0],heap[i]);
        heapifyDown(heap,i,0);
    }
    printHeap(heap,n);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int heap[n];
        for(int i = 0; i<n;i++)
        {
            cin>>heap[i];
        }
        heapSort(heap,n);
    }

}
