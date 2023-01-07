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
	
	int a, b;
	a = b = 0;
	int t = 4;
	while (t--)
	{
		int x;
		cin >> x;
		a += x;
	}
	t = 4;
	while (t--)
	{
		int x;
		cin >> x;
		b += x;
	}
	if (a == b)
		cout << "Tie" << endl;
	else if (a > b)
		cout << "Gunnar" << endl;
	else
		cout<<"Emma"<<endl;
}
int main() {
	int t = 1;
	//cin >> t;
	while (t--)
		solve();

}