#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(v) ((v).begin()), ((v).end())
#define sz(v) v.size()
#define endl "\n"
const int N = 3e2 + 7;
int arr[N], cnt[N], cur[N];
vector<int>pos[N];
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
                ss << arr[u] << ",}"[!~nxt[u]];
            }
            ss << ",]"[i + 1 == cnt];
        }
        return ss.str();
    }
}dsu;

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    dsu.init(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= n; j++)
        {
            char c;
            cin >> c;
            if (c == '1')
                dsu.merge(i, j);
        }
    }

    for (int i = 1; i <= n; i++)
        pos[dsu.find(i)].push_back(arr[i]);
  
    for (int i = 1; i <= n; i++) {
        sort(pos[i].rbegin(), pos[i].rend());
    }
 
    for (int i = 1; i <= n; i++) {
        int cur = dsu.find(i);
        cout << pos[cur].back() << " ";
        pos[cur].pop_back();
    }



}