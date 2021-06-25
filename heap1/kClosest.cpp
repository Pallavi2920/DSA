// Given an unsorted array and two numbers x and k, find k closest values to x.
// Input : arr[] = {10, 2, 14, 4, 7, 6}, x = 5, k = 3
#include<bits/stdc++.h>
using namespace std;
void kClosest(int heap[], int k, int n,int x)
{
        priority_queue<pair<int,int>>max;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
                max.push({abs(heap[i]-x),heap[i]});
                if(max.size()>k)
                {
                    max.pop();
                }
        }
        while(max.size()!=0)
        {
            cout<<max.top().second<<" ";
            max.pop();
        }
        // reverse(ans.begin(),ans.end());
        // for(int i=0;i<ans.size();i++)
        // {
        //     cout<<ans[i]<<" ";
        // }
        cout<<'\n';
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,x;
        cin>>n>>x>>k;
        int heap[n];
        for(int i=0;i<n;i++)
        {
            cin>>heap[i];
        }
        kClosest(heap,k,n,x);
    }
}
