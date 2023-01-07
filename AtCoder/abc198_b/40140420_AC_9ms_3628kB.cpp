#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
string s;
cin>>s;

while(s.back()=='0')
{
    s.pop_back();
}
string r=s;
reverse(r.begin(),r.end());

if(s==r)
    cout<<"Yes";
else
    cout<<"No";

}

