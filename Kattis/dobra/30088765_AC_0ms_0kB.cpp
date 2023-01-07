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
bool Vowel(char c)
{
	return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}
string s;
ll mem[101][4][4][2];
ll solve(int idx, int Vcnt, int Ccnt, int L)
{
	if (Vcnt >=3 || Ccnt >=3)
		return 0;
	if (idx == sz(s))
		return L;
	ll &ret = mem[idx][Vcnt][Ccnt][L];
	if (~ret)
		return ret;
	ret = 0;

	int V = Vowel(s[idx]);


	if (s[idx] == '_')
	{
		for (char i = 'A'; i <= 'Z'; i++)
		{
			if (Vowel(i))V = 1;
			ret += solve(idx + 1, Vcnt*V + Vowel(i),  Ccnt* (!V)  + (!Vowel(i)), L || (i == 'L'));
			V = 0;
		}
	
	}
	else
		ret += solve(idx + 1, V * Vcnt + Vowel(s[idx]), (!V) * Ccnt + (!Vowel(s[idx])), L || (s[idx] == 'L'));
	return ret;
}
int main()
{

	cin >> s;
	memset(mem, -1, sizeof mem);	
	cout << solve(0, 0, 0, 0) << endl;

}