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

        int n;
        cin>>n;
        vector<int>v(n);
        for(auto &i:v)cin>>i;


        int ans=0;
        for(int i=0;i<n-1;i++)
        {
            int mn=min(v[i],v[i+1]);
            int mx=max(v[i],v[i+1]);

            while(mx>2*mn)
            {
                mn*=2;
                ans++;
            }
        }
        cout<<ans<<endl;


    }

}
