#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_set>
#define endl '\n'
using namespace std;

#define all(v) ((v).begin()), ((v).end())
#define sz(v) v.size()
typedef long long ll;
double mem[101][101], p;
int n;
double dp(int a, int b)
{
	if (a == n || b == n)
		return (a == n);
	double& ret = mem[a][b];
	if (ret == ret)
		return ret;
	return ret = dp(a + 1, b) * p + dp(a, b + 1) * (1.00 - p);
}
void solve()
{
	cin >> n >> p;
	memset(mem, -1, sizeof mem);
	cout << fixed << setprecision(2) << dp(0, 0) << endl;
	
}
int main() {
	int t = 1;
	cin >> t;
	while (t--)
		solve();

}