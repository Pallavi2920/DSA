#include<bits/stdc++.h>
using namespace std;
void negative(int arr[],int n)
{
    int left=0,right=n-1;
    while(left<=right)
    {
        if(arr[left]>0 && arr[right]<0)
        {
            swap(arr[left++],arr[right--]);
        }
        else if(arr[left]<0 && arr[right]<0)
        {
            left++;
        }
        else if(arr[left]>0 && arr[right]>0)
        {
            right--;
        }
        else
        {
            left++;
            right--;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
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
        negative(arr,n);
    }
}
