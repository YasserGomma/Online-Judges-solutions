#include<bits/stdc++.h>
#include<unordered_map>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;
int main()
{
    FIO

       int t;
       cin>>t;
       while(t--)
       {
           int n;
           cin>>n;
           vector<int>v(n);
           for(auto &i:v)cin>>i;

           if(is_sorted(v.begin(),v.end()))
           {
               cout<<0<<endl;
               continue;
           }

           ll ans=0;
           for(int i=1;i<n;i++)
           {
               if(v[i-1]>v[i])
                ans+=(v[i-1]-v[i]);
           }
           cout<<ans<<endl;
       }













}
