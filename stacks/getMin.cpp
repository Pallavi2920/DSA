#include<bits/stdc++.h>
#define SIZE 10000
using namespace std;
int top=-1,s[SIZE],minNum;
void push(int data)
{
  if(top==-1)
  {
      top++;
      s[top]=data;
      minNum=data;
  }
  else
  {
      if(data>=minNum)
      {
        top++;
        s[top]=data;
        return;
      }
      else if(data<minNum)
      {
        int temp;
        temp=2*data-minNum;
        top++;
        s[top]=temp;
        minNum=data;
        return;
      }
  }
}
void  pop()
{
    if(top==-1)
    {
      cout<<"-1"<<endl;
      return;
    }
    if(s[top]>=minNum)
    {
      top--;
    }
    else
    {
      minNum=2*minNum-s[top];
      top--;
    }

}
int topp()
{
  if(top==-1)
  {
    return -1;
  }
  else
  {
    if(s[top]>=minNum)
    {
      return s[top];
    }
    else
    {
      return minNum;
    }
  }
}
int getMin()
{
  if(top==-1)
    return -1;
  else
    return minNum;
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int c,data;
    cin>>c;
    switch (c) {
      case 1:cin>>data;
             push(data);
             break;
      case 2:pop();
             break;
      case 3:cout<<topp()<<endl;
             break;
      case 4:cout<<getMin()<<endl;
             break;
    }

  }
}
