#include <bits/stdc++.h>

using namespace std;

int main()
{

   int n;
   cin>>n;
   int cnt=0;
   vector<int>v(n+1);
   for(int i=0;i<n;i++)
   {
       cin>>v[i];
       cnt+=(v[i]==1);
   }
   v[v.size()-1]=1;
   cout<<cnt<<endl;

   for(int i=1;i<v.size();i++)
   {
    if(v[i]==1)
        cout<<v[i-1]<<" ";
   }

}


