#include<bits/stdc++.h>
using namespace std;
int middleElement(int a,int b,int c)
{
    int x = std::max(a,b);
    int y = std::min(a,b);
    x=max(x,c);
    y=min(y,c);
    return (a+b+c)-x-y;
}
int main()
{
  int a,b,c;
  cin>>a>>b>>c;
  cout<<middleElement(a,b,c)<<endl;
}
