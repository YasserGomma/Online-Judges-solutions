#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;
int main()
{
    FIO

    int n;
    cin>>n;
    int x;
    set<int>st;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        if(x<=n)
            st.insert(x);
    }
    cout<<n-st.size();

}
