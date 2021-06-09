// Maximum of all subarray of size k
#include<bits/stdc++.h>
using namespace std;


void Window(std::vector<int>arr,int n,int k)
{
    list<int>li;
    std::vector<int> result;
    int i=0,j=0;
    while(j<arr.size())
    {
        while(li.size()>0 && li.back()<arr[j])
        {
            li.pop_back();
        }
        li.push_back(arr[j]);

    if(j-i+1<k)
      j++;
    else if(j-i+1==k)
    {
        result.push_back(li.front());
        if(li.front()==arr[i])
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
    int n,k;
    cin>>n>>k;
    std::vector<int> arr;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    Window(arr,n,k);
}
