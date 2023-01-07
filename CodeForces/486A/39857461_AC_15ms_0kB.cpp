#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;
int main()
{
long long n;
cin>>n;
if(n&1)
    cout<<-(++n)/2;
else
    cout<<n/2;

}
