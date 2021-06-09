#include<bits/stdc++.h>
#include<queue>
using namespace std;
queue<int>r;
queue<int>s;
void valuableTime(queue<int>r, queue<int>s)
{
    int cost = 0;
    while(r.size() != 0 && s.size() != 0)
    {
          if(r.front()==s.front())
          {
            r.pop();
            s.pop();
            cost++;
          }
          else
          {
            int temp1 = r.front();
            r.pop();
            r.push(temp1);
            cost++;
          }
    }
    cout<<cost<<endl;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        r.push(temp);
    }
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        s.push(temp);
    }
    valuableTime(r, s);
}
