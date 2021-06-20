// Mean Heap using bottom up approach
// For 0 based indexing parent will be at (i/2)-1, left child at 2*i+1 and right child at 2*i+1
#include<bits/stdc++.h>
using namespace std;
void heapifyDown(int heap[], int n, int i)
{
    int l = 2*i+1;
    int r = 2*i+2;
    int s = i;
    if(l<n && heap[l]<heap[i])  s = l;
    if(r<n && heap[r]<heap[s])  s = r;
    if(s!=i)
    {
        swap(heap[i],heap[s]);
        heapifyDown(heap,n,s);
    }
}
void buildHeap(int heap[],int n)
{
    for(int i = (n/2-1);i>=0;i--)
    {
        heapifyDown(heap,n,i);
    }
}
void printHeap(int heap[],int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        cout<<heap[i]<<" ";
    }
}

int main()
{
    cout<<"Enter the number of test cases:"<<endl;
    int t;
    cin>>t;
    while(t--)
    {
        cout<<"Enter the number of elements you want to insert in a heap:"<<endl;
        int n;
        cin>>n;
        int heap[n];
        cout<<"Enter the heap elements:"<<endl;
        for(int i=0;i<n;i++)
        {
            cin>>heap[i];
        }
        buildHeap(heap,n);
        cout<<"Min Heap is :"<<endl;
        printHeap(heap,n);
        cout<<endl;
    }
}
