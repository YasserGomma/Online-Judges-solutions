#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_set>
#define endl '\n'
using namespace std;

#define all(v) ((v).begin()), ((v).end())
#define sz(v) v.size()
typedef long long ll;

void solve()
{
	
	double m, n, a, i;
		cin >> m >> n;
		a = m, i = m;
		while (i--) 
			a -= pow(i / m, n);
		cout << fixed << setprecision(9) << a << endl;
}
int main() {
	int t = 1;
	//cin >> t;
	while (t--)
		solve();

}