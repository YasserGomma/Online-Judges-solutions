#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;
int main()
{
    FIO

    int n;
    cin>>n;
    map<int,int>mp;
    int mx=0,x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        mp[x]++;
    }
    
    for(auto it:mp)
        mx=max(it.second,mx);
    cout<<mx;

}
