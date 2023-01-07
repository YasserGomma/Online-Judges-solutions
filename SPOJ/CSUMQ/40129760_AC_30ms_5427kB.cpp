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

  int n;
  cin>>n;
  vector<int>pref(100005,0);
  for(int i=0;i<n;i++)
  {
      int x;
      cin>>x;
      if(i)
        pref[i]+=pref[i-1];
        pref[i]+=x;
  }
  int q;
  cin>>q;
  while(q--)
  {
      int l,r;
      cin>>l>>r;

      if(l==0)
        cout<<pref[r]<<endl;
      else
        cout<<pref[r]-pref[l-1]<<endl;
  }
}



