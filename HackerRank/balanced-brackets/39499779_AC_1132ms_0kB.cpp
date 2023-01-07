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

        bool valid=1;
        for(int i=0; i<s.size(); i++)
        {
            char cur=s[i];
            if(cur=='(' or cur=='{' or cur=='[')
            {
                st.push(cur);
                continue;
            }
            if(st.empty())
            {
                valid=0;
                break;
            }

            char tp=st.top();
            if((cur=='}' and tp=='{') or
                    (cur==']' and tp=='[') or
                    (cur==')' and tp=='('))
            {
                st.pop();
            }
            else
            {
                valid=0;
                break;
            }

        }
        if(valid and st.empty())
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;


    }

}


