#include<bits/stdc++.h>
#include<unordered_map>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;
int main()
{
    FIO

        int n;
        cin>>n;
        map<int,int>mp;
        int mx=0;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            mp[x]++;
            mx=max(mx,mp[x]);
        }
        cout<<mx;













}
