#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define endl                         '\n'
#define Ceil(x,y)             ((x+y-1)/y)
#define sz(s)               (int)s.size()
#define RT(x)           return cout<<x,0;
#define mem(x,y)    memset(x,y,sizeof(x))
#define all(v) ((v).begin()), ((v).end())
#define vi                    vector<int>
#define pii                 pair<int,int>
#define watch(x) cout<<(#x)<<" = "<<x<<endl
#define forr(i, n) for (int i = 0; i < int(n); i++)
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
const double PI = acos(-1), EPS = 1e-7;
const int OO = 0x3f3f3f3f, N = 1e7 + 5, mod = 1e9 + 7;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll x, ll y) { return (!y) ? x : gcd(y, x % y); }
ll lcm(ll x, ll y) { return ((x / gcd(x, y)) * y); }
void yasser()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
#endif
}
vector<ll>fac(1000009);
void  sieve_v1() {
	for (int i = 1; i <= 1000009; i++) {
		
			for (int j = i ; j <=1000000; j += i) 
			{
				fac[j]++;
			}
	}
}
vector<int>prime(1000003);
vector<ll>v;
ll arr[1000009];
int main()
{
	yasser();
	v.push_back(2);
	for (int i = 0; i <= 1000000; i++)
		prime[i] = 1;
	prime[0] = prime[1] = 0;
	for (int i = 4; i <= 1000000; i += 2) {
		prime[i] = 0;
	}
	for (int i = 3; i < 1000000; i += 2) {
		if (prime[i]) {
			v.push_back(i);
			for (int j = 2 * i; j < 1000000; j += i) {
				prime[j] = 0;
			}
		}
	}
	int idx = 0;
	ll cnt = 0;
	for (int m = 2; m <= 1000000; m++)
	{
		idx = 0;
		ll n = m;
		while (v[idx]*v[idx]<=n)
		{
			while (n % v[idx] == 0)n /= v[idx], cnt++;
			idx++;
		}
		if (n > 1)cnt++;
		arr[m] = cnt;
	}
	int n;
	while (cin >> n && n)
	{
		cout << arr[n] << endl;
	}
}
