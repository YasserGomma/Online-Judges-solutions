#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_set>
#define endl '\n'
using namespace std;

#define all(v) ((v).begin()), ((v).end())
#define sz(v) v.size()
typedef long long ll;
void babadeDiffrenceEngine(vector<vector<int>> &def, int m)
{
	while (sz(def.back()) > 1)
	{
		vector<int>n, &p = def.back();
		for (int i = 0; i < sz(p) - 1; ++i)
		{
			n.emplace_back(p[i + 1] - p[i]);
		}
		def.emplace_back(n);

	}

	def.back().resize(m + 1, def.back().back());
	for (int i = sz(def) - 1, j = 1; i > 0; --i, ++j)
	{
		vector<int> &cur = def[i], &prv = def[i - 1];
		for (int k = 0; k < m; ++k)
			prv.emplace_back(cur[k + j] + prv[k + j]);
	}
}
void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>>v;
	vector<int>x(n);
	for (auto& i : x)
		cin >> i;
	v.emplace_back(x);
	babadeDiffrenceEngine(v, m);
	for (int j = n; j < sz(v[0]); ++j)
	{
		cout << v[0][j];
		if (j != sz(v) - 1)
			cout << " ";
		else
			cout << endl;
	}
}
int main() {
	int t = 1;
	cin >> t;
	while (t--)
		solve();

}