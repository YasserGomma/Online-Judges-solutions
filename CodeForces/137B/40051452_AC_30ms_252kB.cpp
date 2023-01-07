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
        set<int>st;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            if(x<=n)
                st.insert(x);
        }
        cout<<n-st.size();













}
