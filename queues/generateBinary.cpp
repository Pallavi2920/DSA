#include<bits/stdc++.h>
#include<vector>
#include<queue>
using namespace std;
void generateBinary(int n)
{
    std::vector<string>result;
    queue<string>nums;
    nums.push("1");
    for(int i=0;i<n;i++)
    {
        string temp = nums.front();
        result.push_back(temp);
        nums.pop();
        nums.push(temp+'0');
        nums.push(temp+'1');
    }
    for(int i=0 ; i<result.size();i++)
    {
        cout<<result[i]<<" ";
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
        generateBinary(n);
    }
}
