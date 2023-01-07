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
    ll m, n;
    while (cin >> n >> m) {
        if (m == 1 && n == 1) break;
        ll a, b, c, d, pm, pn;
        a = d = 0;
        b = c = pm = pn = 1;
        while (1) {
            if (pn == n && pm == m) break;
            if (pm * n < pn * m) {
                cout << "L";
                b = pn, d = pm;
            }
            else {
                cout << "R";
                a = pn;
                c = pm;
            }
            pn = a + b;
            pm = c + d;
        }
        cout << endl;
    }
}
int main() {
    int t = 1;
    //cin >> t;
    while (t--)
        solve();

}