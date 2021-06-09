#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int *sumTwo(int arr[],int n,int target)
{
    static int index[2];
    int left=0,right=n-1;
    while(left<right)
    {
        if(arr[left]+arr[right]>target)
            right--;
        else if(arr[left]+arr[right]<target)
            left++;
        else
        {
            index[0]=left+1;
            index[1]=right+1;
            return index;
        }
    }
      index[0]=-1;
      index[1]=-1;
      return index;
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
    int target;
    cin>>target;
    sort(arr,arr+n);
    int *p;
    p=sumTwo(arr,n,target);
    for(int i=0;i<2;i++)
    {
      cout<<*(p+i)<<" ";
    }
    cout<<endl;
    return 0;
}
