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

bool isOperator(char symbol)
{
	return  ((symbol == '*') || (symbol == '/') || (symbol == '+') || (symbol == '-'));
}
bool isOperand(char symbol) {
	return (symbol >= '0' && symbol <= '9');
}

int degree(char symbol) {
	switch (symbol) {
	case '(': return 1;
	case ')': return 1;
	case '+': return 2;
	case '-': return 2;
	case '*': return 3;
	case '/': return 3;
	}
}
int main()
{

	nGu();
	int t;
	cin >> t;
	string tmp;
	getline(cin, tmp);
	cin.ignore();
	bool fr = 1;
	while (t--)
	{
		string t, in = "", out;
		while (getline(cin, t))
		{
			if (sz(t))
				in += t;
			else
				break;
		}
		stack<int>st;
		for (int i = 0; i < sz(in); i++)
		{
			if (isOperand(in[i])) {
				out += in[i];
			}
			else if (isOperator(in[i])) {
				while (!st.empty() && degree(in[i]) <= degree(st.top())) {
					out += st.top();
					st.pop();
				}
				st.push(in[i]);
			}
			else if (in[i] == '(') {
				st.push(in[i]);
			}
			else if (in[i] == ')') {
				while (st.top() != '(') {
					out += st.top();
					st.pop();
				}
				st.pop();
			}

		}
		while (!st.empty()) {
			out += st.top();
			st.pop();
		}
		if (fr) {
			fr = !fr;
			cout << out << endl;
		}
		else
			cout << endl << out << endl;
	}
}