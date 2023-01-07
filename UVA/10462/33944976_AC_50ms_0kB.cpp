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
struct edge {
    int from, to;
    ll w;
    edge(int from, int to, ll w) :from(from), to(to), w(w) {}
    bool operator <(const edge e)const {
        return w > e.w;
    }
};
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
}tree;
pair<ll, vector<edge>>kurskal(vector<edge>adj,int n)
{
    tree.init(n);
    ll mnCost = 0;
    vector<edge>edges;
    priority_queue<edge>q;
    for (auto it : adj)q.push(it);
    while (q.size())
    {
        edge e = q.top();
        q.pop();
        if (tree.merge(e.from, e.to))
        {
            mnCost += e.w;
            edges.push_back(e);
        } 
       
    }
    if (sz(edges) != n - 1)
        return make_pair(LLONG_MAX, vector<edge>());
    return make_pair(mnCost, edges);
}
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
    for(int id=1;id<=t;id++)
    {
        cout << "Case #" << id << " : ";
        int n,m;
        cin >> n>>m;
        vector<edge>adj;
        while (m--)
        {
            int u, v, c;
            cin >> u >> v >> c;
            --u, --v;
            adj.push_back(edge(u, v, c));

        } 
        pair<ll, vector<edge>>MST = kurskal(adj, n);
        if (MST.first == LLONG_MAX)
        {
            cout << "No way" << endl;
            continue;
        }
        ll ans = LLONG_MAX;
        for (int i=0;i<sz( MST.second);++i)
        {
            edge cur = MST.second[i];
            for (int ii = 0; ii < sz(adj); ++ii)
            {
                edge now = adj[ii];
                if (cur.from == now.from and cur.to == now.to and cur.w == now.w)
                {
                    adj[ii] = edge(0, 0, INT_MAX);
                    ans = min(ans, kurskal(adj, n).first);
                    adj[ii] = now;
                }
            }

        }
        if (ans == LLONG_MAX)
            cout << "No second way" << endl;
        else
            cout << ans << endl;
    }

}