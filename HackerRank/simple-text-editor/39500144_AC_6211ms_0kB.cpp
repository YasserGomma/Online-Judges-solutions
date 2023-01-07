#include <bits/stdc++.h>

using namespace std;

int main()
{
   int q;
   cin>>q;
   stack<string>preState;
   string s="";
   while(q--)
   {
      int qType;
      cin>>qType;

      if(qType==1)
      {
          string a;
          cin>>a;
          preState.push(s);
          s+=a;
      }
      else if(qType==2)
      {
          int k;
          cin>>k;
          preState.push(s);

          while(k--)
            s.pop_back();
      }
      else if(qType==3)
      {
          int idx;
          cin>>idx;
          cout<<s[idx-1]<<endl;
      }
      else
      {
          s=preState.top();
          preState.pop();
      }
   }
}


