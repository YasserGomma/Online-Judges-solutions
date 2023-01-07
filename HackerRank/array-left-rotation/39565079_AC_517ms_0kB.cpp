#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,d;
    cin>>n>>d;
    deque<int>q;

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        q.push_back(x);
    }
    while(d--)
    {
      q.push_back(q.front());
      q.pop_front();
    }

    while(q.size())
    {
        cout<<q.front()<<" ";
        q.pop_front();
    }

}


