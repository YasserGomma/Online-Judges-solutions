#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(v) ((v).begin()), ((v).end())
#define sz(v) v.size()
#define endl "\n"
const int N = 5e4 + 10 + 5, SQ = 225;

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int n,m;
	cin >> n>>m;
	vector<int>nxt(n + 1, 0), v(n + 1);
	stack<int>st;
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	for (int i = 1; i <= n; i++) {
		while (!(st.empty()) && v[st.top()] < v[i]) {
			nxt[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}

	int ans = 0;
	while(m--)
	{
		int st, en;
		cin >> st >> en;
		if (!nxt[st]||nxt[st]>=en)
			ans++;
	}
	cout << ans << endl;

}