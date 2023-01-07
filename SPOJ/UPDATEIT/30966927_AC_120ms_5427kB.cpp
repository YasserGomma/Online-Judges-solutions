#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(v) ((v).begin()), ((v).end())
#define sz(v) v.size()
#define endl "\n"


int main() {
    std::ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n,u;
        cin>>n>>u;
        vector<ll>v(n+2,0);
        while(u--)
        {
            int l,r,val;
            cin>>l>>r>>val;
            if(l>r)
                swap(l,r);
            v[l]+=val;
            v[r+1]-=val;
        }
        for(int i=1;i<=n;++i)
            v[i]+=v[i-1];
        int q;
        cin>>q;
        while(q--)
        {
            int i;
            cin>>i;
            cout<<v[i]<<endl;
        }
    }


}
