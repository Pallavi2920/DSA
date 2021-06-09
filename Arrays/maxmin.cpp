#include<bits/stdc++.h>
using namespace std;
void maxmin(int arr[],int n)
{
    int max=INT_MIN,min=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
          max=arr[i];
        else if(arr[i]<min)
          min=arr[i];
    }
    cout<<"Minimum : "<<min<<endl;
    cout<<"Maximun : "<<max<<endl;
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
    maxmin(arr,n);
}
