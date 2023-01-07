#include<bits/stdc++.h>
#include<unordered_map>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;
bool cmp(int a,int b)
{
    return a<b;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   int t;
   cin>>t;
   while(t--)
   {
       map<int,int>frq;

       int n;
       cin>>n;
       int flag=true;
       while(n--)
       {
           int x;
           cin>>x;
           frq[x]++;
           if(frq[x]>1)
            flag=false;
       }
       if(flag)
        cout<<"prekrasnyy"<<endl;
       else
        cout<<"ne krasivo"<<endl;
   }

}



