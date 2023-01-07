#include <bits/stdc++.h>

using namespace std;

int main()
{

    string s="";
    stack<string>preState;
    int q;
    cin>>q;
    while(q--)
    {
        int qType;
        cin>>qType;
        if(qType==1)
        {
            preState.push(s);
            string ap;
            cin>>ap;
            s+=ap;
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
            string pre=preState.top();
            preState.pop();
            s=pre;
        }
    }
}


