#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_set>
#define endl '\n'
using namespace std;

#define all(v) ((v).begin()), ((v).end())
#define sz(v) v.size()
typedef long long ll;

const int N = (int)1e3 + 5;
char g[N][N];
bool vis[N][N];
ll dp[N][N];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };
int n;
void dfs(int i, int j)
{
	vis[i][j] = 1;
	for (int idx = 0; idx < 4; ++idx)
	{
		int ni = i + dx[idx];
		int nj = j + dy[idx];
		if (ni < 0 || ni >= n || nj < 0 || nj >= n)
			continue;
		if (!vis[ni][nj] && g[ni][nj] != '#')
			dfs(ni, nj);

	}
}
const ll mod = (1LL << 31) - 1;
void solve()
{
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> g[i];

	dp[1][1] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; j++)
		{
			if (g[i - 1][j - 1] != '#') {
				if (i == 1 && j == 1)
					continue;
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
			}
		}
	if (dp[n][n])
		cout << dp[n][n] << endl;
	else
	{
		dfs(0, 0);
		if (vis[n - 1][n - 1])
			cout << "THE GAME IS A LIE" << endl;
		else
			cout << "INCONCEIVABLE" << endl;
	}


}
int main() {
	int t = 1;
	//cin >> t;
	while (t--)
		solve();

}