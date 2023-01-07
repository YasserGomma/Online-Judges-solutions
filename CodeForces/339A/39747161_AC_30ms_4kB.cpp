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

    char c;
    int cnt=0;
    vector<char>v;
    while(cin>>c)
    {
        if(cnt%2==0)
            v.push_back(c);
        cnt++;
    }
    sort(all(v));

    for(int i=0;i<v.size();i++)
    {
        cout<<v[i];
        if(i!=v.size()-1)
            cout<<'+';
    }

}


