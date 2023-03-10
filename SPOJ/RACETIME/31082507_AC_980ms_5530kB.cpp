#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define all(v) ((v).begin()), ((v).end())
#define sz(v) v.size()
#define endl "\n"
const int N = 1e5 + 5, SQ = 318;
int arr[N],pre[N],n,sq;
int query(int st,int en,int x)
{
  int stB=st/sq,enB=en/sq;
  int ret=0;
  if(stB==enB)
  {
    for(int i=st;i<=en;i++)
	{
      ret+=(arr[i]<=x);
	}
    return ret;
  }

  for(int i=st;i<(stB+1)*sq;i++)
  {
	ret += (arr[i] <= x);
  }
  for(int i=(enB*sq);i<=en;i++)
  {
	ret += (arr[i] <= x);
  }

  for(int i=stB+1;i<enB;i++)
  {
    ret+= upper_bound(pre+(i*sq),pre+(i+1)*sq,x)-(pre+(i*sq));
  }
  return ret;
}
void modify(int pos,int val)
{
  int bId=pos/sq;
  int bSt=bId*sq;
  int bEn=min(n,bSt+sq);
  int ind= lower_bound(pre+bSt,pre+bEn,arr[pos])-pre;
  arr[pos]=val;
  pre[ind]=val;
  while(ind>bSt and pre[ind-1]>pre[ind])
	swap(pre[ind],pre[ind-1]),ind--;
  while(ind<bEn-1 and pre[ind+1]<pre[ind])
	swap(pre[ind],pre[ind+1]),ind++;
}
int main() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);cout.tie(NULL);
  int q,st,en,x,ind;
  cin>>n>>q;
  sq= ceil(sqrt(n));
  for(int i=0,j=0;i<n;i+=sq,j++)
  {
	int k;
	for( k=0;k<sq and k+i<n;k++)
	{
	  cin>>arr[i+k];
	  pre[i+k]=arr[i+k];
	}
	sort(pre+sq*j,pre+sq*j+k);
  }
  char c;
  while(q--)
  {
	cin>>c;
	if(c=='C')
	{
	  cin>>st>>en>>x;
	  cout<<query(--st,--en,x)<<endl;
	}
	else
	{
	  cin>>ind>>x;
	  modify(--ind,x);
	}
  }
}
