#define _CRT_SECURE_NO_WARNINGS

#include<bits/stdc++.h>
using namespace std;
#define all(v) ((v).begin()), ((v).end())
#define sz(v) v.size()
#define endl "\n"

typedef long long ll;

void  T()
{
	std::ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
}

int main()
{

	T();
	int n, s;
	while (cin >> n >> s)
	{
		vector<int>v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		int l, r, ans, cnt;
		l = r = ans = 0,cnt = n+1;
		while (r < n)
		{
			ans += v[r];
			r++;
			while (l < r&& ans - v[l] >= s)
			{
				ans -= v[l], l++;
			}
			if(ans >= s)
			cnt = min(cnt, r - l );
		}
		if (cnt == n + 1)
			cout << 0 << endl;
		else
			cout << cnt << endl;
	}


}