#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_set>
#define endl '\n'
using namespace std;

#define all(v) ((v).begin()), ((v).end())
#define sz(v) v.size()
typedef long long ll;
ll mem[100][100] ;
ll dp(int n, int m) {
	if (n < m || m < 0) return 0;
	if (n == m || m == 0) return 1;
	if (mem[n][m]) return mem[n][m];
	return mem[n][m] = dp(n - 1, m) + dp(n - 1, m - 1);
}
void solve()
{
	ll m, n = 0;
	int k, t = 59;
	cin >> m >> k;
	if (m == 0 || k == 1) {
		cout << 1 << endl;
	}
	else {
		k--;
		while (m) 
		{
			if (dp(t, k) <= m)
			{
				m -= dp(t, k);
				n |= (1LL << t);
				k--;
			}
			t--;
		}
		cout << n << endl;
	}
}
int main() {
	int t = 1;
	//cin >> t;
	while (t--)
		solve();

}