#include<iostream>
#include<string>
#include<stack>
#include<ctype.h>
using namespace std;
stack<int>s;
int main()
{
    int n;
    cin>>n;

    while(n--)
    {
        string exp;
        cin>>exp;
        if ( !(exp.empty()) && isdigit(exp[0]) ) //isdigit is meant to check whether a single character is a digit or not, not a string. That's why the call isdigit(s) fails to compile.
        // check whether the first character of the string is a digit before attempting to use std::stoi.
        {
          int num = std::stoi(exp);
          s.push(num);
        }
        else
        {
          string :: iterator it=exp.begin();
          int t2=s.top();
          s.pop();
          int t1=s.top();
          s.pop();
          if(*it=='+')
            s.push(t1+t2);
          else if(*it=='-')
            s.push(t1-t2);
          else if(*it=='*')
            s.push(t1*t2);
          else if(*it=='/')
            s.push(t1/t2);
        }
    }
    cout<<s.top()<<endl;
}
