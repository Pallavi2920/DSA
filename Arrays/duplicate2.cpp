#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
int main()
{
      int n;
      cin>>n;
      int arr[n];
      for(int i=0;i<n;i++)
      {
        cin>>arr[i];
      }
      unordered_map<int, int> umap;
       for(int i = 0; i<n ; i++){
          umap.insert(make_pair(i,arr[i]));
       }
      for(auto &ele:umap)
      {
        cout<<ele.first<<" "<<ele.second<<endl;
      }
       cout<<endl;
}
