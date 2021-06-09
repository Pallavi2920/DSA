#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.length();
    char temp;
    for(int i=0,j=n-1;i<n/2;i++,j--)
    {
        temp=s[i];
        s[i]=s[j];
        s[j]=temp;
    }
    cout<<s<<endl;
}
