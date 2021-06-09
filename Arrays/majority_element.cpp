#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int findMajority(int arr[],int n)
{
  int prev=INT_MIN,max_element=-1,count=0;
  for(int i=0;i<n;i++)
  {
    if(arr[i]==prev)
      count++;
    else
    {
      prev=arr[i];
      count=1;
    }
    if(count>n/2)
    {
      max_element=arr[i];
      return max_element;
    }
  }
  return -1;
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
  cout<<findMajority(arr,n)<<endl;
}
