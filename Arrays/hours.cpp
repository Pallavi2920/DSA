#include <iostream>
#include <string>
using namespace std;
string timeConversion(string pv,string pt)
{
      if(pt=="PM")
      {
          if(pv[0]=='1' && pv[1]=='2')
          {
              return pv;
          }
          else
          {
              int temp = int(pv[0]-48);
              temp *=10;
              temp+= int(pv[1]-48);
              temp +=12;
              int rem = temp%10;
              pv[1] =(char)(rem+48);
              pv[0] = (char)(int(temp/10)+48);
              return pv;
          }
      }
      else
      {
          if(pv[0]=='1' && pv[1]=='2')
          {
              int temp = int(pv[0]-48);
              temp *=10;
              temp += int(pv[1]-48);
              temp -=12;
              int rem = temp%10;
              pv[1] = (char)(rem + 48);
              pv[0] = (char)(int(temp/10) + 48);
              return pv;
          }
          else
          {
              return pv;
          }
      }
}
void solve()
{
    string pv,pt;
    cin>>pv>>pt;
    string p = timeConversion(pv,pt);
    int n;
    cin>>n;
    while(n--)
    {
        string a,b,c,d;
        cin>>a>>b>>c>>d;
        string l = timeConversion(a,b);
        string r = timeConversion(c,d);
        if(p>=l && p<=r)
        {
            cout<<"1";
        }
        else
        {
            cout<<"0";
        }
        cout<<endl;
    }

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
        cout<<endl;
    }
    return 0;
}
