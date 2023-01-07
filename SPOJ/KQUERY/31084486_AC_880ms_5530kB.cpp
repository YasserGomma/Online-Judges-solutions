#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define all(v) ((v).begin()), ((v).end())
#define sz(v) v.size()
#define endl "\n"
const int N = 3e4 + 5;
int arr[N], pre[N], sq,n,q;
int query(int st, int en, int x)
{
	int stB = st / sq, enB = en / sq;
	int ret = 0;
	if (stB == enB)
	{
		for (int i = st; i <= en; i++)
		{
			ret += (arr[i] > x);
		}
		return ret;
	}

	for (int i = st; i < (stB + 1) * sq; i++)
	{
		ret += (arr[i] > x);
	}
	for (int i = (enB * sq); i <= en; i++)
	{
		ret += (arr[i] > x);
	}

	for (int i = stB + 1; i < enB; i++)
	{
		ret += (pre+(i+1)*sq)-(lower_bound(pre + (i * sq), pre + (i + 1) * sq, x+1));
	}
	return ret;
}
int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	sq = ceil(sqrt(n));
	for (int i = 0, j = 0; i < n; i += sq, j++)
	{
		int k;
		for (k = 0; k < sq and k + i < n; k++)
		{
			cin >> arr[i + k];
			pre[i + k] = arr[i + k];
		}
		sort(pre + sq * j, pre + sq * j + k);
	}
	cin >> q;
	while(q--)
	{
		int l, r, val;
		cin >> l >> r >> val;
		cout << query(--l, --r, val) << endl;
	}
	
}