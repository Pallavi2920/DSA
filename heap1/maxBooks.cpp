// Maximum Books
// Rahul is fond of books and has a list containing costs of N books he wants to purchase but he has only k amount of money available to purchase books.
// The task is to find the maximum number of books Rahul can buy with the amount k.

#include<bits/stdc++.h>
using namespace std;

void heapifyDown(int heap[],int n, int i)
{
    int l = 2*i+1;
    int r = 2*i+2;
    int s = i;
    if(l<n && heap[l]>heap[i])  s=l;
    if(r<n && heap[r]>heap[s])  s=r;
    if(s!=i)
    {
        swap(heap[i],heap[s]);
        heapifyDown(heap,n,s);
    }
}

void buildHeap(int heap[], int n)
{
    for(int i=(n/2)-1;i>=0;i--)
    {
        heapifyDown(heap,n,i);
    }
}

void printHeap(int heap[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<heap[i]<<" ";

    }
    cout<<endl;
}
void heapSort(int heap[],int n)
{
      for(int i=n-1;i>0;i--)
      {
          swap(heap[0],heap[i]);
          heapifyDown(heap,i,0);
      }
}
int maxBooks(int heap[],int n,int k)
{
    int i=0;
    while(k>=heap[i])
    {
        k = k-heap[i];
        i++;
    }
    return i;
}
int main()
{
    int t;
    cout<<"Enter the number of test cases:";
    cin>>t;
    cout<<"\n";
    while(t--)
    {
        int n,k;
        cout<<"Enter the value of n and k:";
        cin>>n>>k;
        cout<<'\n';
        int heap[n];
        for(int i=0;i<n;i++)
        {
            cin>>heap[i];
        }
        buildHeap(heap,n);
        cout<<"Max Heap:";
        printHeap(heap,n);
        heapSort(heap,n);
        cout<<"Array after applying heap sort is:";
        printHeap(heap,n);
        int c = maxBooks(heap,n,k);
        cout<<"Max Number of books can be bought is:"<<c<<"\n";

    }
    return 0;
}
