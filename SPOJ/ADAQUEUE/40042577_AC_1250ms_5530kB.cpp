#include<bits/stdc++.h>
#include<unordered_map>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;
int main()
{



    int q;
    cin>>q;
    bool reversed=false;
    deque<int>dq;
    while(q--)
    {
        string Qtype;
        cin>>Qtype;
        if(Qtype=="reverse")
        {
            reversed=!reversed;
            continue;
        }

        if(reversed)
        {
            if(Qtype=="toFront")
                Qtype="push_back";
            else if(Qtype=="push_back")
                Qtype="toFront";
            else if(Qtype=="front")
                Qtype="back";
            else
                Qtype="front";
        }

        if(Qtype=="front")
        {
            if(dq.empty())
                cout<<"No job for Ada?"<<endl;
            else
            {
                cout<<dq.front()<<endl;
                dq.pop_front();
            }
        }
        else if(Qtype=="back")
        {
            if(dq.empty())
                cout<<"No job for Ada?"<<endl;
            else
            {
                cout<<dq.back()<<endl;
                dq.pop_back();
            }
        }
         else if(Qtype=="toFront")
        {
           int x;
           cin>>x;
           dq.push_front(x);
        }
        else if(Qtype=="push_back")
        {

            int x;
           cin>>x;
           dq.push_back(x);
        }



    }









}
