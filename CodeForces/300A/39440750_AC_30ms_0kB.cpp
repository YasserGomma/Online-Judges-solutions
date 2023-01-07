#include <bits/stdc++.h>

using namespace std;
#define all(v) ((v).begin()), ((v).end())
#define sz(v) v.size()
#define endl "\n"
typedef long long ll;
int main()
{


int n;
cin>>n;

vector<int>neg,pos,zero;
int x;
for(int i=0;i<n;i++)
{
    cin>>x;
    if(x<0)
        neg.push_back(x);
    else if(x>0)
        pos.push_back(x);
    else
        zero.push_back(x);
}
if(neg.size()%2==0)
{
    zero.push_back(neg.back());
    neg.pop_back();
}
if(pos.empty())
{
    pos.push_back(neg.back());
    neg.pop_back();
    pos.push_back(neg.back());
    neg.pop_back();
}

cout<<neg.size()<<" ";
for(auto it:neg)
    cout<<it<<" ";
cout<<endl;

cout<<pos.size()<<" ";
for(auto it:pos)
    cout<<it<<" ";
cout<<endl;

cout<<zero.size()<<" ";
for(auto it:zero)
    cout<<it<<" ";
cout<<endl;





}
