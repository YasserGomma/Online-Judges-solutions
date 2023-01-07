#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_set>
#define endl '\n'
using namespace std;

#define all(v) ((v).begin()), ((v).end())
#define sz(v) v.size()
typedef long long ll;

const int N = (int)1e2 + 5;
int arr[N], temp[N];
void solve()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	cin >> arr[i],temp[i]=arr[i];
	sort(temp, temp + n);
	double cnt = 0, mx = temp[n - 1] + temp[n - 2],all = (n * (n - 1)) / 2.00;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] + arr[j] == mx)
				cnt++;
		}
	}
	//cout << cnt << " " << mx << endl;
	cout << fixed << setprecision(7) << (cnt / all) << endl;


}
int main() {
	int t = 1;
	cin >> t;
	while (t--)
		solve();

}