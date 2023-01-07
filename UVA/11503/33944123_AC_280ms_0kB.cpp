#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define all(v) ((v).begin()), ((v).end())
#define sz(v) v.size()
#define endl "\n"
typedef long long ll;
const int N = 1e5+9;
struct DSU
{
    int par[N], sz[N], sets[N], pos[N], tail[N], nxt[N], cnt;
    void init(int n)
    {
        memset(nxt, -1, n * sizeof(nxt[0]));
        iota(tail, tail + n, 0);
        iota(par, par + n, 0);
        iota(sets, sets + n, 0);
        iota(pos, pos + n, 0);
        fill(sz, sz + n, 1);
        cnt = n;
    }
    int find(int x)
    {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }
    bool merge(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v) return false;
        if (sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        int p = pos[v];
        pos[sets[p] = sets[--cnt]] = p;
        int& t = tail[u];
        nxt[t] = v;
        t = tail[v];
        return true;
    }
    string toString()
    {
        stringstream ss;
        ss << '[';
        for (int i = 0; i < cnt; i++)
        {
            ss << '{';
            for (int u = sets[i]; ~u; u = nxt[u])
            {
                ss << u << ",}"[!~nxt[u]];
            }
            ss << ",]"[i + 1 == cnt];
        }
        return ss.str();
    }
}dsu;
void FAST() {
    ios_base::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
}
int main()
{
    FAST();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        dsu.init(100005);
        map<string, int>id;
        int cnt = 1, i = 0;
        cin >> n;
        while (n--)
        {
            string a, b;
            cin >> a >> b;
            int u, v;
            if (id.find(a) == id.end())
                id[a] = i++;
            if (id.find(b) == id.end())
                id[b] = i++;
            u = id[a], v = id[b];
            dsu.merge(u, v);
            cout << max(dsu.sz[dsu.par[u]], dsu.sz[dsu.par[v]]) << endl;

        }
    }

}