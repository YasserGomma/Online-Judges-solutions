#include <bits/stdc++.h>
using namespace std;
#define all(v) ((v).begin()), ((v).end())
#define sz(v) v.size()
#define endl "\n"


typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        map<int,int>mp;
        int tr;
        for(int i=0;i<n;i++)
        {
            cin>>tr;
            mp[tr]=1;
        }
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            cin>>tr;
            if(mp.count(tr))
            cnt++;
        }
        cout<<cnt<<endl;
    }


}


