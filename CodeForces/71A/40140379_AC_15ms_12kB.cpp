#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string s;
        cin>>s;

        if(s.size()<=10)
            cout<<s<<endl;
        else
            cout<<s.front()<<s.size()-2<<s.back()<<endl;
    }

}



