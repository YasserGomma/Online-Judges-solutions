#include<bits/stdc++.h>
#include<unordered_map>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;
int a[30],b[30];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {

        int n,k;
        cin>>n>>k;

        for(int i=0; i<n; i++)
            cin>>a[i];
        for(int i=0; i<n; i++)
            cin>>b[i];

        sort(a,a+n);

        sort(b,b+n);
        reverse(b,b+n);


        for(int i=0;i<n;i++)
        {
            if(a[i]<b[i] && k>0)
            {
                swap(a[i],b[i]);
                k--;
            }
        }

        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum=sum+a[i];
        }
        cout<<sum<<endl;


    }


}


