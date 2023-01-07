#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define all(v) ((v).begin()), ((v).end())
#define sz(v) v.size()
#define endl "\n"
const int N = 1e3 + 30;
struct bit2D
{
	int tree[N][N];
	void init()
	{
		memset(tree, 0, sizeof tree);

	}
	ll get(int i, int j)
	{
		ll ret = 0;
		for (i++; i; i -= (i & (-i)))
		{
			for (int jj = j + 1; jj; jj -= (jj & (-jj)))
			{
				ret += tree[i - 1][jj - 1];
			}
		}
		return ret;
	}
	void add(int i, int j, ll val)
	{
		for (i++; i <= N; i += (i & (-i)))
		{
			for (int jj = j + 1; jj <= N; jj += (jj & (-jj)))
			{
				tree[i - 1][jj - 1] += val;
			}
		}
	}
	ll get(int si, int sj, int ei, int ej)
	{
		return get(ei, ej) - get(ei, sj - 1) - get(si - 1, ej) + get(si - 1, sj - 1);

	}

}bit;
int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int t, n;
	cin >> t;
	while (t--)
	{
		bit.init();
		int n; cin >> n;
		string s;
		while (cin >> s and s != "END")
		{

			if (s == "SET")
			{
				int i, j, val;
				cin >> i >> j >> val;
				bit.add(i, j, - bit.get(i, j,i,j));
				bit.add(i, j, val);
			}
			else
			{
				int si, sj, ei, ej;
				cin >> si >> sj >> ei >> ej;
				cout << bit.get(si, sj, ei, ej) << endl;
			}
		}
		cout << endl;
	}
}