#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    deque<pair<int,int>>dq;

    for(int i=1;i<=n;i++)
    {
        int val;
        cin>>val;
        dq.push_back(make_pair(val,i));
    }

    while(dq.size()>1)
    {
      pair<int,int>fr=dq.front();
      dq.pop_front();
      int val=fr.first;
      val-=m;
      if(val>0)
      {
          dq.push_back(make_pair(val,fr.second));
      }
    }
    cout<<dq.front().second;
}


