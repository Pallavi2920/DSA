#include<bits/stdc++.h>
using namespace std;


int main()
{
    int low = 0;
    int high = 1;
    int possible = high + low - 1;
    int max = (int)(log(possible)/log(2))+1;
    cout<<max<<endl;
}
