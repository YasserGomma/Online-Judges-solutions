#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    map<char,int>mp;

    for(auto &it:s)
    {
        it=tolower(it);
       mp[it]++;

    }

    if(mp.size()==26)
        cout<<"YES";
    else
        cout<<"NO";

}
