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
vector<string>R = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };
vector<int>A = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
string solve(int x)
{
	string ans = "";
	int idx = 0;
	while (x)
	{
		if (x >= A[idx])
		{
			x -= A[idx];
			ans += R[idx];
		}
		else
			idx++;
	}
	return ans;
}
int main()
{

	T();
	map<int, string>AtoR;
	map<string, int>RtoA;
	for (int i = 0; i < 4000;++i)
	{
			string s = solve(i);
			AtoR[i] = s;
			RtoA[s] = i;
	}
	string in;
	while (cin >> in)
	{
		if (isdigit(in[0]))
		{
			int x = stoi(in);
			cout << AtoR[x] << endl;
		}
		else
			cout << RtoA[in] << endl;
	}


}