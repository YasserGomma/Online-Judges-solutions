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
    int t;
    cin>>t;

    deque<int>q;
    while(t--)
    {
        int qType;
        cin>>qType;

        if(qType==1)
        {
            int n;
            cin>>n;
            q.push_back(n);
        }
        else if(qType==2)
        {
            if(sz(q)) //!q.empty()
            {
                q.pop_back();

            }
        }
        else
        {
            if(q.size())
            {
                cout<<q.back()<<endl;
            }
            else
            {
                cout<<"Empty!"<<endl;
            }
        }

    }




}
