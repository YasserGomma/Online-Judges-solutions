#include<bits/stdc++.h>
#include<unordered_map>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    int arr[11][11];
    int ans=0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==0 || j==0)
                arr[i][j]=1;
            else
                arr[i][j]=arr[i-1][j]+arr[i][j-1];

            if(arr[i][j]>ans)
                ans=arr[i][j];
        }
    }


    cout<<ans;


}


