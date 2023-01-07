#include<bits/stdc++.h>
#include<unordered_map>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;
int arr[1000009];
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
    cin>>arr[i];

   int l,r;
   cin>>l>>r;
   l--,r--;

   for(int i=l;i<=r;i++)
    cout<<arr[i]<< " ";




}


