#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
void _Sectumsempra_()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
#endif
}
bool cmp(pair<string,pair<int,int>>p1,pair<string, pair<int, int>>p2)
{
	if (p1.first != p2.first)return p1.first<p2.first;
	if (p1.second.first != p2.second.first)return p1.second.first > p2.second.first;
	if (p1.second.second != p2.second.second) return p1.second.second < p2.second.second;

}
typedef long long ll;
#define bay_bay return 0;
#define fori(n) for(int i=0;i<n;++i)
#define forsz(s )for(int i=0;i<s.size();++i)
#define all(v) ((v).begin()), ((v).end())
#define read(FILE) freopen(FILE,"r",stdin)
#define write(FILE) freopen(FILE,"w",stdout)
#define sz(v) v.size()
#define endl "\n"
#define sfi(n) scanf("%d",&n)
#define pfi(n) printf("%d",n)
#define sfll(n) scanf("%ld",&n)
#define pfll(n) printf("%ld",n)
#define sff(n) scanf("%f",&n)
#define pff(n) printf("%f",n)
#define sfd(n) scanf("%lf",&n)
#define pfd(n) printf("%lf",n)
#define pfdset(n) printf("%.3lf",n)
#define sfc(n) printf("%c",&n)
#define pfc(n) printf("%c",n)
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll arr[100007];
int main()
{
	_Sectumsempra_();
	int n;
	cin >> n;
	fori(n)
		cin >> arr[i];
	if (n == 1)
	{
		if (arr[0] == 15)
			cout << "DOWN";
		else if (arr[0] == 0)
			cout << "UP" << endl;
		else
			cout << -1 << endl;
	}
	else if (arr[n - 1] == 15)cout << "DOWN" << endl;
	else if (arr[n - 1] == 0)cout << "UP" << endl;
	else if (arr[n - 1] > arr[n - 2])cout << "UP" << endl;
	else if (arr[n - 1] < arr[n - 2])cout << "DOWN" << endl;


}