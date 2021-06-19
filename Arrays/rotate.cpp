#include<bits/stdc++.h>
using namespace std;
void reverseArray(std::vector<int> &v,int l,int ub)
{
    while(l<ub)
    {
        int temp = v[l];
        v[l] = v[ub];
        v[ub] = temp;
        l++;
        ub--;
    }
}
int main()
{
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    std::vector<int> v;
    cout<<"Enter the array elements:"<<endl;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    int d;
    cout<<"Enter the value of d:"<<endl;
    cin>>d;
    reverseArray(v,0,d-1);
    reverseArray(v,d,n-1);
    reverseArray(v,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
