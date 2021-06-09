#include<bits/stdc++.h>
using namespace std;
bool kOverlap(std::vector<pair<int ,int>> pairs,int k)
{
  std::vector<pair<int,int>> vec;
  for(int i=0;i<pairs.size();i++)
  {
    vec.push_back(make_pair(pairs[i].first,-1));
    vec.push_back(make_pair(pairs[i].second,+1));
  }
  sort(vec.begin(),vec.end());
  stack<pair<int , int>>st;
  for(int i=0;i<vec.size();i++)
  {
    pair<int,int>curr=vec[i];
    if(curr.second==-1)
    {
      st.push(curr);
    }
    else
    {
      st.pop();
    }
    if(st.size()>=k)
    {
      return true;
    }
  }
  return false;
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    std::vector<pair<int,int>> pairs;
    int n,k;
    cin>>n>>k;
    int st,ed;
    for(int i=0;i<n;i++)
    {
      cin>>st>>ed;
      pairs.push_back(make_pair(st,ed));
    }
    if(kOverlap(pairs,k))
    {
      cout<<"Yes"<<endl;
    }
    else
    {
      cout<<"No"<<endl;
    }
  }
  return 0;
}
