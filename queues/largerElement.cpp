#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n-2;i++)
    {
          int max  = INT_MIN;
          for(int j=i;j<i+k;j++)
          {
              if(arr[j]>max)
              {
                  max = arr[j];
              }
          }
          cout<<max<<" ";
    }
    cout<<endl;
}
