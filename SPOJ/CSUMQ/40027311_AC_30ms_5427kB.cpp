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
    vector<int>v(n);

    for(auto &i:v)
        cin>>i;

    vector<int>pre(n);
    pre[0]=v[0];
    for(int i=1;i<n;i++)
        pre[i]=v[i]+pre[i-1];

    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;

        if(l==0)
            cout<<pre[r]<<endl;
        else
            cout<<pre[r]-pre[l-1]<<endl;
    }

}
