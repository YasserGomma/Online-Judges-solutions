#include<bits/stdc++.h>
#include<unordered_map>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
#define ll long long


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int>v(n);
    for(auto &i:v)cin>>i;
    if(n==1)
    {
        cout<<1<<endl;
        return 0;
    }
    sort(v.begin(),v.end());
    int idx=n-1;
    int ans=0;
    for(int i=n/2-1;i>=0;i--)
    {
        if(v[i]*2<=v[idx])
        {
            ans++;
            idx--;
        }
    }
    cout<<n-ans;





}

