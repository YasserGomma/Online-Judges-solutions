#include<bits/stdc++.h>
#include<unordered_map>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
#define ll long long
const int mx=1e5+5;
ll n,k;
vector<ll>a,b;
bool ok(ll mid,ll k)
{
    for(int i=0;i<n;i++)
    {
        if(mid*a[i]>b[i])
        {
            ll total=mid*a[i];
            total-=b[i];
            k-=total;
            if(k<0)
                return 0;
        }

    }
    return 1;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    a.resize(n);
    b.resize(n);

    for(auto &it:a)cin>>it;
    for(auto &it:b)cin>>it;

    ll l=0,h=2e9,ans=0;
    while(l<=h)
    {
        ll mid=(l+h)/2;

        if(ok(mid,k))
        {
            l=mid+1;
            ans=mid;
        }
        else
        {
            h=mid-1;
        }

    }
    cout<<ans;




}

