#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;
int main()
{
int n;
cin>>n;
int ans=0;
for(int i=1;i<=n;i++)
    ans+=i;
cout<<ans;


}
