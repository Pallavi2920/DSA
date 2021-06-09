#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;

  while(t--)
  {
      int n;
      cin >>n;
      int maxm = INT_MIN, minm = INT_MAX;
      for (int i = 0; i<n;i++)
      {
          int a;
          cin >> a;
          maxm = max (maxm, a);
          minm = min(minm,a);
      }
      cout << 2 * (maxm -minm)<< endl;
    }
    return 0;
}
