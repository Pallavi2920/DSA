// First negative integer in every window of size k

#include<bits/stdc++.h>
using namespace std;
void firstNegative(int arr[],int n,int k)
{
    list<int>li;
    std::vector<int> result;
    int i=0,j=0;
    while(j<n)
    {
        if(arr[j]<0)
        {
            li.push_back(arr[j]);
        }
        if(j-i+1<k)
          j++;
        else if(j-i+1==k)
        {
            if(li.size()>0)
            {
                  result.push_back(li.front());
            }
            else
                result.push_back(0);

            if(arr[i]==li.front())
            {
                li.pop_front();
            }
            i++;
            j++;
        }
    }
    for (auto x = result.begin(); x != result.end(); ++x)
        cout << *x << " ";
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
        int k;
        cin>>k;
        firstNegative(arr,n,k);
        cout<<"\n";
    }
}
