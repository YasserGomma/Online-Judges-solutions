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
    vector<int>v(n),pos,neg,zero;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        if(v[i]>0)
            pos.push_back(v[i]);
        else if(v[i]<0)
            neg.push_back(v[i]);
        else
            zero.push_back(v[i]);
    }

    if(sz(neg)%2==0){
        zero.push_back(neg.back());
        neg.pop_back();
    }
    if(!sz(pos))
    {
        pos.push_back(neg.back());
        neg.pop_back();
        pos.push_back(neg.back());
        neg.pop_back();
    }


    cout<<sz(neg)<<" ";
    for(int i=0;i<sz(neg);i++)
        cout<<neg[i]<<" ";
    cout<<endl;

     cout<<sz(pos)<<" ";
    for(int i=0;i<sz(pos);i++)
        cout<<pos[i]<<" ";
    cout<<endl;

     cout<<sz(zero)<<" ";
    for(int i=0;i<sz(zero);i++)
        cout<<zero[i]<<" ";
    cout<<endl;




}
