#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
clock_t T;
#define ctime cerr << "Time : " << double(clock() - T) / CLOCKS_PER_SEC << endl
#define all(v) ((v).begin()), ((v).end())
#define sz(v) v.size()
#define endl "\n"
#define deb(x)   cout << "[" <<#x << "=" << x << "]" << endl
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
constexpr auto EPS = 1e-7;
const int mod = (int)1e9 + 7;
#define clr(v, d)		memset(v, d, sizeof(v))
int dxn[] = { -1,-2,-2,-1,1,2,2,1 };
int dyn[] = { -2,-1,1,2,2,1,-1,-2 };
int dx[] = { 0, 1, 0, -1, 1, 1, -1, -1 };
int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
ll gcd(ll a, ll b) { return (a) ? gcd(b % a, a) : b; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
void nGu()
{
	std::ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
#endif
}
ll dp[101][101];
unsigned long long ncr(ll n, ll r) {
	if (n == r) return 1;
	if (n < r) return 0;
	ll& ret = dp[n][r];
	if (~ret)
		return ret;
	return ret = ncr(n - 1, r) * n / (n - r);
}
int main()
{
	nGu();
	int t;
	cin >> t;
	cin.ignore();
	while (t--)
	{
		string s;
		getline(cin, s);
		vector<int>v;
		int num = 0;
		for (int i = 0; i < sz(s); i++)
		{
			if (s[i] == ' ')
			{
				v.push_back(num);
				num = 0;
				continue;
			}
			if (i == sz(s) - 1)
			{
				num = num * 10 + (s[i] - '0');
				v.push_back(num);

			}
			num = num * 10 + (s[i] - '0');
		}
		ll mx = 0;
		for (int i = 0; i < sz(v); i++)
		{
			for (int j = 0; j < sz(v); j++)
			{
				if (i != j)
					mx = max(mx, gcd(v[i], v[j]));
			}
		}
		cout << mx << endl;
	}
}