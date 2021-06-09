#include<bits/stdc++.h>
#include<vector>
#include<utility>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
    }
    stack<pair<int ,int >> s;
    std::vector<int> v;
    for(int i=0;i<n;i++)
    {
      if(s.empty())
      {
        v.push_back(-1);
      }
      else if(s.size()>0 && s.top().first>arr[i])
      {
        v.push_back(s.top().second);
      }
      else if(s.size()>0 && s.top().first<=arr[i])
      {
        while(s.size()>0 && s.top().first<=arr[i])
        {
          s.pop();
        }
        if(s.size()==0)
        {
          v.push_back(-1);
        }
        else
        {
          v.push_back(s.top().second);
        }
      }
      s.push(make_pair(arr[i],i));
    }
    for(int i=0;i<n;i++)
    {
      v[i]= i-v[i];
    }
    for(int i=0;i<n;i++)
    {
      cout<<v[i]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
