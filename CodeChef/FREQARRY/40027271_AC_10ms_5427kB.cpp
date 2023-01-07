#include<bits/stdc++.h>
#include<unordered_map>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;
int main()
{
    FIO

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        set<int>st;
        int x;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            st.insert(x);
        }

        if(st.size()==n)
        {
            cout<<"prekrasnyy"<<endl;
        }
        else
        {
            cout<<"ne krasivo"<<endl;
        }
    }

}
