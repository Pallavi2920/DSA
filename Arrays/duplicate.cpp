#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
bool duplicates(int arr[],int n)
{
  int prev=INT_MIN;
  for(int i=0;i<n;i++)
  {
    if(arr[i]==prev)
      return 1;
    else
      prev=arr[i];
  }
  return 0;
}

int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  sort(arr,arr+n);
  if(duplicates(arr,n))
    cout<<"true"<<endl;
  else
    cout<<"false"<<endl;
}
