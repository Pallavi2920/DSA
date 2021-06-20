// Mean heap using Top Down Approach
#include<bits/stdc++.h>
using namespace std;
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
void printHeap(int heap[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout<<heap[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    cout<<"Enter the number of test case:"<<endl;
    int t;
    cin>>t;
    while(t--)
    {
         int n;
         cout<<"Enter the number of elements you want to insert:";
         cin>>n;
         int heap[n];
         int ele;
         for(int i=0;i<n;i++)
         {

            cin>>ele;
            insert(heap,ele,i);
         }
         printHeap(heap,n);
    }
    return 0;
}
