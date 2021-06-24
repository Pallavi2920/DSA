// Given an array of n elements, where each element is at most k away from its target position, devise an algorithm that sorts in O(n log k) time.
// For example, let us consider k is 2, an element at index 7 in the sorted array, can be at indexes 5, 6, 7, 8, 9 in the given array.
//
// Example:
// Input : arr[] = {6, 5, 3, 2, 8, 10, 9}
// k = 3
// Output : arr[] = {2, 3, 5, 6, 8, 9, 10}
#include<bits/stdc++.h>
using namespace std;
void nearlySorted(int heap[], int k, int n)
{
        priority_queue<int,vector<int>,greater<int>>minh;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
                minh.push(heap[i]);
                if(minh.size()>k)
                {
                    ans.push_back(minh.top());
                    minh.pop();
                }
        }
        while(minh.size()!=0)
        {
            ans.push_back(minh.top());
            minh.pop();
        }
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<'\n';
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
        nearlySorted(heap,k,n);
    }
}
