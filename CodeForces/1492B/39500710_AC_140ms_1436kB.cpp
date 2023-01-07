#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];

        vector<int>ans;
        vector<bool>vis(n+1,0);

        int cur=n;
        while(cur>=1)
        {
            if(vis[cur])
            {
                cur--;
                continue;
            }
            int cnt=0,idx=0;
            for(int i=v.size()-1;i>=0;i--)
            {
                cnt++;
                if(v[i]==cur)
                {
                    idx=i;
                    break;
                }
            }
            for(int i=idx;i<v.size();i++)
            {
                ans.push_back(v[i]);
                vis[v[i]]=1;
            }
            while(cnt--)
            {
                v.pop_back();
            }

        }

        for(auto it:ans)
            cout<<it<<" ";

        cout<<endl;

    }

}


