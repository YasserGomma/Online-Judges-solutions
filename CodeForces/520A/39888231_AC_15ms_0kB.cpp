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
   set<char>st;

    for(auto &it:s)
    {
        it=tolower(it);
       st.insert(it);
    }

    if(st.size()==26)
        cout<<"YES";
    else
        cout<<"NO";

}
