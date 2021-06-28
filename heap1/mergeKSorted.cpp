#include<bits/stdc++.h>
using namespace std;;
typedef pair<int, pair<int, int>> ppi;

void mergeKSorted(vector<vector<int>>mat)
{
      priority_queue<ppi,vector<ppi>,greater<ppi>> minh;
      vector<int>ans;
      for(int i=0;i<mat.size();i++)
      {
          minh.push({mat[i][0],{i,0}});
      }
      while(minh.size()!=0)
      {
          ppi curr = minh.top();
          ans.push_back(curr.first);
          int i = curr.second.first;
          int j = curr.second.second;
          minh.pop();
          if(j+1<mat[i].size())
          {
              minh.push({mat[i][j+1],{i,j+1}});
          }
      }
      for(int i=0;i<ans.size();i++)
      {
          cout<<ans[i]<<" ";
      }
      cout<<endl;
}
int main()
{
    vector<vector<int>>mat;
    cout<<"Enter the number of rows:";
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        vector<int>v;
        cout<<"Enter the number of elements you want to insert :";
        int m;
        cin>>m;
        for(int i =0;i<m;i++)
        {
            int ele;
            cin>>ele;
            v.push_back(ele);
        }
        mat.push_back(v);
    }
    mergeKSorted(mat);
    cout<<mat.size()<<endl;

}
