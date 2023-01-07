#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(v) ((v).begin()), ((v).end())
#define sz(v) v.size()
#define endl "\n"


const int Nod = 1e6 + 1,N=1<<19;
int cnt[Nod+10],arr[N],n,m;
struct BIT {
	ll tree[N];
	void init()
	{
		memset(tree, 0, sizeof tree);
	}
	void add(int pos, int val)
	{
		for (++pos; pos <= N; pos += (pos & (-pos)))
			tree[pos - 1] += val;
	}
	ll get(int pos)
	{
		ll ret = 0;
		for (++pos; pos; pos -= (pos & (-pos)))
			ret += tree[pos - 1];
		return ret;

	}
	int find(int t)
	{
		int st = 0;
		for (int sz = N >> 1; sz; sz >>= 1)
		{
			if (tree[st + sz - 1] < t)
			{
				t -= tree[(st += sz) - 1];
			}
		}
		return st;
	}
}bit;
set<int>st;
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
	bit.init();
	for (int i = 1; i <= Nod; ++i)
		for (int j = i; j <= Nod; j += i)
			cnt[j]++;

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		bit.add(i, arr[i]);
		st.insert(i);
	}
	while(m--)
	{
		int typ, l, r;
		cin >> typ >> l >> r;
		if(typ&1)
		{
			set<int>::iterator it = st.lower_bound(l);
			vector<int>rem;
			while (it!=st.end() and *it<=r)
			{
				int idx = *it;
				bit.add(idx, -arr[idx]);
				arr[idx] = cnt[arr[idx]];
				bit.add(idx, arr[idx]);
				if (arr[idx] == cnt[arr[idx]])
					rem.push_back(idx);
				it++;
			}
			for (auto i : rem)
				st.erase(i);
		}
		else
		{
			cout << bit.get(r) - bit.get(l - 1)<<endl;
		}
	}
	
	


}