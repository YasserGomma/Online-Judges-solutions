#include <bits/stdc++.h>

using namespace std;

int main()
{

   int n,k;
   cin>>n>>k;

   deque<int>dq;

   for(int i=0;i<n;i++)
   {
    int x;
    cin>>x;
    dq.push_back(x);
   }

   while(k--)
   {
       int cur=dq.front();
       dq.pop_front();

       dq.push_back(cur);
   }

   for(int i=0;i<n;i++)
    cout<<dq[i]<<" ";

}


