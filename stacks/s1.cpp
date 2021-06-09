#include<bits/stdc++.h>
#include<algorithm>
#define SIZE 10000
using namespace std;
int top=-1,s[SIZE];
void push(int data)
{
  if(top==SIZE-1)
  {
    cout<<"Stack Overflow"<<endl;
  }
  top++;
  s[top]=data;
  return;
}
int pop()
{
  if(top==-1)
  {
    cout<<"Stack Empty"<<endl;
    return INT_MIN;
  }
  int temp=s[top];
  top--;
  return temp;
}
int topp()
{
  if(top==-1)
  {
    cout<<"Stack Empty"<<endl;
    return INT_MIN;
  }
  return s[top];
}
int getMin()
{
  sort(s,s+SIZE,greater<int>());
  return s[top];
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
      case 2:cout<<"Popped Data is:"<<pop()<<endl;
             break;
      case 3:cout<<"Top Element is:"<<topp()<<endl;
             break;
      case 4:cout<<"Minimum Element is:"<<getMin()<<endl;
             break;
    }

  }
}
