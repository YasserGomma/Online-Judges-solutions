#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cin>>n;

    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    sort(v.begin(),v.end());

    if(n==1)
    {
        return cout<<1,0;
    }

    int idx=n-1,ans=0;
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
