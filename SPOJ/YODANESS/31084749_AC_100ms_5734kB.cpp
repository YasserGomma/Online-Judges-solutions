#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define all(v) ((v).begin()), ((v).end())
#define sz(v) v.size()
#define endl "\n"
const int N = 1 << 15;
struct BIT {
    int tree[N];
    void init()
    {
        memset(tree, 0, sizeof tree);
    }
    void add(int pos, int val)
    {
        for (++pos; pos <= N; pos += (pos & (-pos)))
            tree[pos - 1] += val;
    }
    int get(int pos)
    {
        int ret = 0;
        for (++pos; pos; pos -= (pos & (-pos)))
            ret += tree[pos - 1];
        return ret;

    }
    int find(int t)
    {
        int st = 0;
        for (int sz = N >> 1; sz; sz >>= 1)
        {
            if (tree[st + sz - 1] < t)
            {
                t -= tree[(st += sz) - 1];
            }
        }
        return st;
    }
}bit;
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        bit.init();
        int n;
        cin >> n;
        map<string, int>cur;
        for (int i = 0; i < n; i++)
        {
            string x;
            cin >> x;
            cur[x] = i + 1;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            string x;
            cin >> x;
            //cout << x << " " << i - (bit.get(cur[x] - 1)) << endl;

            ans += i - (bit.get(cur[x] - 1));
            bit.add(cur[x], 1);
           /* for (int i = 1; i <= n; i++)
                cout << bit.get(i) << " ";
            cout << endl;*/
        }
        cout << ans << endl;


    }

}