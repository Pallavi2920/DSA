#include<bits/stdc++.h>
#include<queue>
#include<vector>
using namespace std;
void binaryQueue(int n)
{
    std::vector<string> s;
    queue<string>nums;
    string temp;
    nums.push("1");
    for(int i=0;i<n;i++)
    {
        temp = nums.front();
        s.push_back(temp);
        nums.pop();
        nums.push(temp+'0');
        nums.push(temp+'1');
    }
    for(int i=0;i<s.size();i++)
    {
        cout<<s[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        binaryQueue(n);
    }
}
