#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;

        stack<char>st;
        bool ok=1;

        for(int i=0; i<s.size(); i++)
        {
            char c=s[i];
            if(c=='{' or c=='(' or c=='[')
            {
                st.push(c);
                continue;
            }
            if(st.empty())
            {
                ok=0;
                break;
            }
            char tp=st.top();
            if((c=='}' and tp == '{')or(c==')' and tp=='(')or(c==']' and tp=='['))
            {
                st.pop();
            }
            else
            {
                ok=0;
                break;
            }
        }
        if(ok and st.empty())
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}


