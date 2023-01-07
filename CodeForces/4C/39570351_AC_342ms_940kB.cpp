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


    map<string,int>mp;

    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        if(mp.count(s))
        {
            cout<<s<<mp[s]<<endl;
        }
        else
        {
            cout<<"OK"<<endl;
        }
        mp[s]++;

    }
}


