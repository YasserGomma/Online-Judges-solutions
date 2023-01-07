#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>pos,neg,zeros;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        if(x>0)
            pos.push_back(x);
        else if(x<0)
            neg.push_back(x);
        else
            zeros.push_back(x);
    }

    if(neg.size()%2==0)
    {
        zeros.push_back(neg.back());
        neg.pop_back();
    }

    if(pos.size()==0)
    {
        pos.push_back(neg.back());
        neg.pop_back();
        pos.push_back(neg.back());
        neg.pop_back();
    }

    cout<<neg.size()<< " ";
    for(auto &it:neg)
        cout<<it<<" ";
    cout<<endl;

    cout<<pos.size()<< " ";
    for(auto &it:pos)
        cout<<it<<" ";
    cout<<endl;

    cout<<zeros.size()<< " ";
    for(auto &it:zeros  )
        cout<<it<<" ";
    cout<<endl;





}


