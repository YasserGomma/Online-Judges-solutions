#include<bits/stdc++.h>
#include<unordered_map>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
#define ll long long

int n,k;
vector<ll>a,b;

bool ok(ll mid)
{
    ll cur = 0;
    for(int i=0;i<n;i++)
    {

        if(mid*a[i]>b[i])
        {
            cur+=(a[i]*mid-b[i]);

            if(cur>k)
            {
                return 0;
            }
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

    for(auto &i:a)cin>>i;
    for(auto &i:b)cin>>i;

    ll l=0,r=2e9,ans=0;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        if(ok(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }

    cout<<ans;







}

