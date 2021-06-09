#include <bits/stdc++.h>
using namespace std;

bool kOverlap(vector<pair<int, int> > pairs, int k)
{
vector<pair<int, int> > vec;
for (int i = 0; i < pairs.size(); i++) {

    vec.push_back(make_pair( pairs[i].first, -1 ));
    vec.push_back(make_pair( pairs[i].second, +1 ));
}
sort(vec.begin(), vec.end());
stack<pair<int, int> > st;
for (int i = 0; i < vec.size(); i++) {
    pair<int, int> cur = vec[i];
    if (cur.second == -1) {
        st.push(cur);
    }
    else {
        st.pop();
    }
    if (st.size() >= k) {
        return true;
    }
}
return false;
}
 int main()
{
int t;
cin>>t;
while(t--)
{
int n,k;
cin>>n>>k;
vector<pair<int, int> > pairs;
int x,y;
for(int i=0;i<n;i++)
{
    cin>>x>>y;
    pairs.push_back(make_pair(x,y));
}
if(kOverlap(pairs,k))
cout<<"Yes"<<endl;
else
{
    cout<<"No"<<endl;
}
}
return 0;
}
