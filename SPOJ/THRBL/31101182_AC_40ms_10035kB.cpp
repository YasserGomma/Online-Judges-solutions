#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(v) ((v).begin()), ((v).end())
#define sz(v) v.size()
#define endl "\n"
const int N = 1e5 + 5, LG = 18;
int sp[LG][N], lg[N], arr[N], n,m;

void buildLOG() {
	lg[0] = -1;
	for (int i = 0; i < N - 1; i++) {
		sp[0][i] = i;
		lg[i + 1] = lg[i] + !(i & (i + 1));
	}
}

void buildSP() {
	static int dummy = (buildLOG(), 0);
	for (int j = 1; (1 << j) <= n; j++) {
		for (int i = 0; i + (1 << j) <= n; i++) {
			int a = sp[j - 1][i];
			int b = sp[j - 1][i + (1 << (j - 1))];
			sp[j][i] = arr[a] > arr[b] ? a : b;
		}
	}

}
int getMaxInd(int st, int en) {
	int sz = en - st + 1;
	int l = lg[sz];
	int a = sp[l][st];
	int b = sp[l][en - (1 << l) + 1];
	return arr[a] > arr[b] ? a : b;

}
int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	buildSP();

	int ans = 0;
	while (m--)
	{
		int st, en;
		cin >> st >> en;
		st--, en-=2;
		ans += (arr[getMaxInd(st, en)] <= arr[st]);

	}
	cout << ans << endl;


}