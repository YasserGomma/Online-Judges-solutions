#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
clock_t T;
#define ctime cerr << "Time : " << double(clock() - T) / CLOCKS_PER_SEC << endl
#define all(v) ((v).begin()), ((v).end())
#define sz(v) v.size()
#define endl "\n"
#define mm(v) memset(v, 0, sizeof(v))
#define deb(x)   cout << "[" <<#x << "=" << x << "]" << endl
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
constexpr auto EPS = 1e-7;
const int mod = (int)1e9 + 7;
int dxn[] = { -1,-2,-2,-1,1,2,2,1 };
int dyn[] = { -2,-1,1,2,2,1,-1,-2 };
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
ll gcd(ll a, ll b) { return (a) ? gcd(b % a, a) : b; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
void nGu()
{
	std::ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
#endif
}
int forbiden[11][11];
int main()
{

	int t;
	cin >> t;
	int cas = 1;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		vector<int>v(n);
		for (int i = 0; i < n; i++)
			v[i] = i + 1;
		memset(forbiden, 0, sizeof forbiden);
		while (k--)
		{
			int a, b;
			cin >> a >> b;
			forbiden[a][b] = forbiden[b][a] = 1;
		}
		int cnt = 0;
		do 
		{
			int path = 1;
			for (int i = 0; i < n; i++)
			{
				int j = (i + 1) % n;
				path &= !forbiden[v[i]][v[j]];

			}
			if (path)
				cnt++;

		} while (next_permutation(v.begin()+1,v.end()));
		cout << "Case #"<< cas++<<": "<< (cnt / 2) % 9901 << endl;
    }
}