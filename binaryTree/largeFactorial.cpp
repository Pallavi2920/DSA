#include<bits/stdc++.h>
using namespace std;
int fact(int num)
{
    if(num==0)  return 1;
    return num*fact(num-1);
}


int main()
{
    int n;
    cin>>n;
    std::vector<int> v,v1;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;

        v1.push_back(fact(temp));
    }
    for(int i=0;i<v1.size();i++)
    {
        cout<<v1[i]<<" ";
    }
    cout<<endl;

}
