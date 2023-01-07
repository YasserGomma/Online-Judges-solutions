#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;
int main()
{
    FIO

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int>a(n),b(n);
        for(auto &i:a)cin>>i;
        for(auto &i:b)cin>>i;

        sort(a.begin(),a.end());
        sort(b.begin(),b.end(),greater<>());

        int ans=0;

        for(int i=0;i<n;i++)
        {
            if(k>0 and a[i]<b[i])
            {
               ans+=b[i];
               k--;
            }
            else
            {
                ans+=a[i];
            }

        }
        cout<<ans<<endl;
    }
}
