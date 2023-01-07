#include <bits/stdc++.h>
using namespace std;
#define all(v) ((v).begin()), ((v).end())
#define sz(v) v.size()
#define endl "\n"
#define int long long

typedef long long ll;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    if(n&1)
        cout<<((n+1)/2)*(-1);
    else
        cout<<n/2;
}


