#include<iostream>
#include<algorithm>
using namespace std;
int kthsmallest(int arr[],int n,int k)
{
    sort(arr,arr+n);
    return (arr[k-1]);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cout<<"The "<<k<<"th smallest element is:"<<kthsmallest(arr,n,k)<<endl;
    }
    return 0;
}
