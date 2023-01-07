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
    int  m, n, sx, sy, k, x, y;
    cin >> m >> n >> sx >> sy >> k;
    vector< pair<int, int> > v;
    while (k--) {
        cin >> x >> y;
        v.push_back({ x,y });
    }
    sort(all(v));
    int ans = INT_MAX, tx, ty;
    do {
        int mn = 0;
        tx = sx, ty = sy;
        for (auto& it : v) {
            mn += abs(tx - it.first) + abs(ty - it.second);
            tx = it.first; ty = it.second;
        }
        mn += abs(sx - tx) + abs(sy - ty);
        ans = min(ans, mn);
    }
    while (next_permutation(v.begin(), v.end()));

    cout << ans << endl;

}
int main() {
    int t = 1;
    cin >> t;
    while (t--)
        solve();

}