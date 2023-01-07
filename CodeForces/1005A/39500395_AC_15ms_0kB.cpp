#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cin>>n;
  vector<int>v(n);
  int cnt=0;
  for(int i=0;i<n;i++)
  {
      cin>>v[i];
      if(v[i]==1)cnt++;
  }
  v.push_back(1);
  cout<<cnt<<endl;
  for(int i=1;i<=n;i++)
  {
      if(v[i]==1)
        cout<<v[i-1]<<" ";
  }
}


