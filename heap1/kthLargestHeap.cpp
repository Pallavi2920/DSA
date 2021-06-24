#include<bits/stdc++.h>
using namespace std;
int kthLargest(int heap[],int k,int n)
{
    priority_queue<int, vector<int>,greater<int>>minh;
    for(int i=0;i<n;i++)
    {
        minh.push(heap[i]);
        if(minh.size()>k)   minh.pop();
    }
    return minh.top();
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
        for(int i=0;i<n;i++)
        {
            cin>>heap[i];
        }
        cout<<kthLargest(heap,k,n)<<endl;
    }
}
