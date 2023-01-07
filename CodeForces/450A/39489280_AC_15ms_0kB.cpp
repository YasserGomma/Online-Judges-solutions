    #include <bits/stdc++.h>

    using namespace std;

    int main()
    {

      int n,m;
      cin>>n>>m;

      deque<pair<int,int>>dq;
      for(int i=0;i<n;i++)
      {
          int x;
          cin>>x;
          dq.push_back(make_pair(x,i+1));
      }
      while(dq.size()>1)
      {
          pair<int,int>cur=dq.front();
          dq.pop_front();

          cur.first-=m;
          if(cur.first>0)
          {
              dq.push_back(cur);
          }
      }
      cout<<dq.front().second;
    }


