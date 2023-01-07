#include <bits/stdc++.h>

using namespace std;
int a[100005];
int b[100005];
int n,k;

bool vaild(long long mid)
{
    long long cur=0;
    for(int i=0;i<n;i++)
    {
        if(mid*a[i]>b[i])
        {
            cur+=(a[i]*mid-b[i]);
            if(cur>k)
                return 0;
        }
    }
    return 1;
}
int main()
{
   cin>>n>>k;

   for(int i=0;i<n;i++)
    cin>>a[i];

   for(int i=0;i<n;i++)
    cin>>b[i];


    long long l=0,r=2e9,ans=0;
    while(l<=r)
    {
        long long mid=(l+r)/2;
        if(vaild(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<ans;


}
