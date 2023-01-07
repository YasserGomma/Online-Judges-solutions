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
string mem[1005][1005];
string solve(int i = 0, int j = sz(s) - 1)
{
    
    if (i == j)return  string(1, s[i]);
    if (i > j)return "";
    string& ret = mem[i][j];
    if (ret != ".")return ret;
    string Mi, Mj, Mall;
    Mi = solve(i + 1, j);
    Mj = solve(i, j - 1);
    Mall = (s[i] == s[j]) ? s[i] + solve(i + 1, j - 1) + s[j] : Mall;
    if (sz(Mi) != sz(Mj))ret = (sz(Mi) > sz(Mj))? Mi : Mj;
    else ret =(Mi < Mj) ? Mi : Mj;
    if (sz(Mall) != sz(ret))ret = (sz(ret) > sz(Mall)) ? ret : Mall;
    else ret = (ret < Mall) ? ret : Mall;
    return ret;
}
int main()
{
    thb7();
    while (cin >> s)
    {
        for (int i = 0; i < sz(s); i++)
            for (int j = 0; j < sz(s); j++)
                mem[i][j] = ".";

        cout << solve() << endl;
    }

}