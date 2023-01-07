#include <bits/stdc++.h>
using namespace std;
#define all(v) ((v).begin()), ((v).end())
#define sz(v) v.size()
#define endl "\n"


typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char c;
    int cnt=0;
    priority_queue<char,vector<char>,greater<char>>pq;
    while(cin>>c)
    {
        if(cnt%2==0)
            pq.push(c);
        cnt++;
    }
    
    while(!pq.empty())
    {
        cout<<pq.top();
        if(pq.size()>1)
        cout<<'+';
        pq.pop();
    }
}


