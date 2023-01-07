#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_set>
#define endl '\n'
using namespace std;

#define all(v) ((v).begin()), ((v).end())
#define sz(v) v.size()
typedef long long ll;

const int N = (int)1e5 + 5;
vector<int>adj[N];
double ans = 0.0;
void dfs(int u, int par, int len, double prob)
{
	int cur = 0;
	for (auto ch : adj[u])
		cur += (ch != par);

	for (auto ch : adj[u])
	{
		if (ch != par)
		{
			dfs(ch, u, len + 1, prob / cur);
		}
	}
	if (!cur)
		ans += (prob * len);
}
void solve()
{
	int n;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0, 0, 0, 1.0);
	cout << fixed << setprecision(7) << ans << endl;
}
int main() {
	int t = 1;
	//cin >> t;
	while (t--)
		solve();

}