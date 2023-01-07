  #include <bits/stdc++.h>

  using namespace std;
  typedef long long ll;
  #define all(v) ((v).begin()), ((v).end())
  #define sz(v) v.size()
  #define endl "\n"
  const int N = 1e5 + 5, SQ = 318;
  int arr[N],pre[SQ],n,sq;

  int RMQ(int st,int en)
  {
    int stB=st/sq,enB=en/sq;
    if(stB==enB)
	  return *min_element(arr+st,arr+en+1);
    int ret=*min_element(arr+st,arr+(stB+1)*sq);
    ret=min(ret,*min_element(arr+(enB*sq),arr+en+1));
    ret=min(ret,*min_element(pre+stB+1,pre+enB));
  }
  int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	sq=ceil(sqrt(n));
	for(int i=0,j=0;i<n;i+=sq,j++)
	{
	  pre[j]=INT_MAX;
	  for(int k=0;k<sq and k+i<n;k++)
	  {
	    cin>>arr[i+k];
	    pre[j]=min(pre[j],arr[i+k]);
	  }
	}
	int q;
	cin>>q;
	while(q--)
	{
	  int st,en;
	  cin>>st>>en;
	  cout<<RMQ(st,en)<<endl;
	}

  }
