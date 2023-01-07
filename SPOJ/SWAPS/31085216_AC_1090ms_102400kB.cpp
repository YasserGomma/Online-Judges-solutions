#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(v) ((v).begin()), ((v).end())
#define sz(v) v.size()
#define endl "\n"
const int N = 25e4 + 5, V = 5e4 + 5, SQ = 5e2 + 5;
int arr[N], n, q, sq;
struct bit2D
{
    int tree[SQ][V];
    void init()
    {
        memset(tree, 0, sizeof tree);

    }
    ll get(int i, int j)
    {
        ll ret = 0;
        for (i++; i; i -= (i & (-i)))
        {
            for (int jj = j + 1; jj; jj -= (jj & (-jj)))
            {
                ret += tree[i - 1][jj - 1];
            }
        }
        return ret;
    }
    void add(int i, int j, ll val)
    {
        for (i++; i <= SQ; i += (i & (-i)))
        {
            for (int jj = j + 1; jj <= V; jj += (jj & (-jj)))
            {
                tree[i - 1][jj - 1] += val;
            }
        }
    }
    ll get(int si, int sj, int ei, int ej)
    {
        return get(ei, ej) - get(ei, sj - 1) - get(si - 1, ej) + get(si - 1, sj - 1);

    }

}bit;
ll tot = 0;
void update(int pos, int val)
{
    int bId = pos / sq;
    int stB = bId * sq;
    int enB = min(n, stB + sq);
    for (int i = stB; i < enB; i++)
    {
        if ((pos<i and arr[pos]>arr[i]) || (pos > i and arr[pos] < arr[i]))
            tot--;
    }
    arr[pos] = val;
    for (int i = stB; i < enB; i++)
    {
        if ((pos<i and arr[pos]>arr[i]) || (pos > i and arr[pos] < arr[i]))
            tot++;
    }
    tot += bit.get(0, arr[pos] + 1, bId - 1, V - 1) + bit.get(bId + 1, 0, sq - 1, arr[pos] - 1);
    bit.add(bId, val, 1);
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    sq = ceil(sqrt(n));
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        update(i, x);
    }
    cin >> q;
    while (q--)
    {
        int pos, x;
        cin >> pos >> x;
        --pos;
        int bId = pos / sq;
        bit.add(bId, arr[pos], -1);
        tot -= bit.get(0, arr[pos] + 1, bId - 1, V - 1) + bit.get(bId + 1, 0, sq - 1, arr[pos] - 1);
        update(pos, x);
        cout << tot << endl;
    }

}