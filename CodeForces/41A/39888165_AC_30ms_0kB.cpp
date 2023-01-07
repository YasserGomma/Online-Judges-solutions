#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;
int main()
{
string a,b;
cin>>a>>b;
reverse(b.begin(),b.end());
if(a==b)
    cout<<"YES";
else
    cout<<"NO";
}
