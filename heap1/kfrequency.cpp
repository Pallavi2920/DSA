// Given an integer array nums and an integer k, return the k most frequent elements.
// You may return the answer in any order.
// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int>mp;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minh;
void kfrequency(int heap[],int n,int k)
{
    for(int i=0;i<n;i++)
    {
        mp[heap[i]]++;
    }
    for(auto i : mp)
    {
        minh.push({i.second,i.first});
        if(minh.size()>k)
        {
            minh.pop();
        }
    }
    while(minh.size()!=0)
    {
        cout<<minh.top().second<<" ";
        minh.pop();
    }
    cout<<'\n';

}

int main()
{
    int n,k;
    cin>>n>>k;
    int heap[n];
    for(int i=0;i<n;i++)
    {
        cin>>heap[i];
    }
    kfrequency(heap,n,k);
}
