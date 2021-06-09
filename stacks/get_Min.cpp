#include<iostream>
#include<stack>
using namespace std;

int minEle;
stack<int>st;

void popp()
{
    if(st.top()>=minEle)
    {
      st.pop();
    }
    else
    {
      st.pop();
      minEle=2*minEle-st.top();
    }
}
void pushh(int x)
{
    if(st.size()==0)
    {
        st.push(x);
        minEle=x;
    }
    if(x>=minEle)
    {
        st.push(x);
    }
    else if(x<minEle)
    {
        st.push(2*x-minEle);
        minEle=x;
    }
}
int topp()
{
    if(st.top()>=minEle)
      return st.top();
    else
      return minEle;
}
int getMin()
{
    if(st.size()==0)
      return -1;
    else
      return minEle;
}
int main()
{
    int choice;
    do {
      cout<<"Enter your choice:"<<endl;
      cin>>choice;
      switch(choice)
      {
        case 1: int x;
                cout<<"Enter Data:"<<endl;
                cin>>x;
                pushh(x);
                break;
        case 2: popp();
                break;
        case 3: cout<<getMin()<<endl;
                break;
        case 4: cout<<topp()<<endl;
                break;
        default:cout<<"Wrong Choice"<<endl;
      }

    } while(choice);

}
