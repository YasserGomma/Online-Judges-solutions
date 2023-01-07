#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_set>
#define endl '\n'
using namespace std;

#define all(v) ((v).begin()), ((v).end())
#define sz(v) v.size()
typedef long long ll;
double a[105];

void solve()
{
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	sort(a, a + n);
	reverse(a, a + n);
	double mx = 0;
	for (int i = 0; i < n; i++) {
		double s = 0;
		for (int j = 0; j <= i; j++) {
			double c = a[j];
			for (int k = 0; k <= i; k++) {
				if (j != k)
					c *= (1 - a[k]);
			}
			s += c;
		}
		mx = max(mx, s);
	}
	cout << fixed << setprecision(10) << mx << endl;
}
int main() {
	int t = 1;
	//cin >> t;
	while (t--)
		solve();

}
