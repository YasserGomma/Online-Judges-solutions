#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(v) ((v).begin()), ((v).end())
#define sz(v) v.size()
#define endl "\n"
const int N = 1 << 18;
struct BIT {
    int tree[N];
    BIT()
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
};
struct multiSet {
    BIT bit;
    multiSet()
    {
        bit.add(0, -1);
    }
    void insert(int val)
    {
        bit.add(val, 1);
    }
    void erase(int val)
    {
        bit.add(val, -1);
    }
    int count(int val)
    {
        return bit.get(val) - bit.get(val - 1);
    }
    int size()
    {
        return bit.get(N - 1) + 1;
    }
    int at(int idx)
    {
        return bit.find(idx);
    }

}myst;

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    map<int, int>real,comp;
    vector<pair<char, int>>qu(n);
	for(int i=0;i<n;i++)
	{
        cin >> qu[i].first >> qu[i].second;
        real[qu[i].second]++;   
	}
    int cur = 1;
	for(auto it=real.begin();it!=real.end();it++)
	{
        comp.insert({ cur,it->first });
        it->second = cur++;
	}
    for(auto it:qu)
    {
        char c=it.first;
        int x=real[it.second];
        if (c == 'I')
        {
            if (!myst.count(x))
                myst.insert(x);
        }
        else if (c == 'D')
        {
            if (myst.count(x))
                myst.erase(x);
        }
        else if (c == 'K')
        {
            x = it.second;
            if (myst.size() < x)
                cout << "invalid" << endl;
            else
                cout<<comp[myst.at(x - 1)] << endl;
        }
        else
        {   
            cout << myst.bit.get(x - 1) + 1 << endl;
        }
    }


}