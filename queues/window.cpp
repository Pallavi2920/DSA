#include<bits/stdc++.h>
#include<queue>
#include<vector>
using namespace std;
std::vector<int> result;
queue<int>q;
void maxInWindow(int arr[], int n, int k)
{
      int i=0,j=0;
      while(j<n)
      {
              while(q.size()>0 && q.back()<arr[j])
              {
                  q.pop();
              }
          q.push(arr[j]);
          if((j-i+1)<k)
            j++;
          else if((j-i+1)==k)
          {
              result.push_back(q.front());
              if(q.front()==arr[i])
              {
                  q.pop();
              }
              i++;
              j++;
          }
      }
}
int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    maxInWindow(arr,n,k);
    for (auto i = result.begin(); i != result.end(); ++i)
        cout << *i << " ";

}
