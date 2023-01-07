#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define all(v) ((v).begin()), ((v).end())
#define sz(v) v.size()
#define endl "\n"
typedef long long ll;
void thb7()
{
    std::ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
}
string s;
pair<int, string> mem[1005][1005];
pair<int, string> take(pair<int, string> a, pair<int, string> b)
{
    if (a.first > b.first) return a;
    if (b.first > a.first) return b;
    return a.second < b.second? a:b;
}
pair<int, string> solve(int i=0, int j=sz(s)-1)
{
    if (i == j)return make_pair(1, string(1,s[i]));
    if (i > j)return make_pair( 0,"");
    pair<int, string>& ret = mem[i][j];
    if (~ret.first)return ret;
    if (s[i] == s[j]) {
        ret.first = 2 + solve(i + 1, j - 1).first;
        ret.second = s[i] + solve(i + 1, j - 1).second + s[j];
        return ret;
    }
    return ret = take(solve(i, j - 1), solve(i + 1, j));

}
int main()
{
    thb7();
    while (cin >> s)
    {
        for (int i = 0; i < sz(s); i++)
            for (int j = 0; j < sz(s); j++)
                mem[i][j].first = -1;

        cout << solve().second << endl;
    }

}