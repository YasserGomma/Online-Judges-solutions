#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,d;
    cin>>n>>d;
    queue<int>q;

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        q.push(x);
    }
    while(d--)
    {
        //one rotation!
        int cur=q.front();//get front
        q.pop(); //delete front
        q.push(cur);//push back again
    }

    while(q.size())
    {
        cout<<q.front()<<" ";
        q.pop();
    }

}


