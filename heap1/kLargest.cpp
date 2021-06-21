#include<bits/stdc++.h>
using namespace std;

void heapifyDown(int heap[],int n, int i)
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
void heapSort(int heap[],int n)
{
        for(int i=n-1;i>0;i--)
        {
                swap(heap[0],heap[i]);
                heapifyDown(heap,i,0);
        }
}
void buildHeap(int heap[],int n)
{
    for(int i=(n/2)-1;i>=0;i--)
    {
            heapifyDown(heap,n,i);
    }
}
void printHeap(int heap[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        cout<<heap[i]<<" ";
    }
    cout<<'\n';
}
int main()
{
    int n,k;
    cin>>n>>k;
    int heap[n];
    for(int i = 0; i<n;i++)
    {
        cin>>heap[i];
    }
    buildHeap(heap,n);
    heapSort(heap,n);
    printHeap(heap,n);
    for(int i=0;i<k;i++)
    {
      cout<<heap[i]<<" ";
    }
    cout<<endl;
}
