#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
clock_t T;
#define ctime cerr << "Time : " << double(clock() - T) / CLOCKS_PER_SEC << endl
#define all(v) ((v).begin()), ((v).end())
#define sz(v) v.size()
#define endl "\n"
#define mm(v) memset(v, 0, sizeof(v))
#define deb(x)   cout << "[" <<#x << "=" << x << "]" << endl
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
constexpr auto EPS = 1e-7;
const int mod = (int)1e9 + 7;
int dxn[] = { -1,-2,-2,-1,1,2,2,1 };
int dyn[] = { -2,-1,1,2,2,1,-1,-2 };
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
ll gcd(ll a, ll b) { return (a) ? gcd(b % a, a) : b; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
void nGu()
{
    std::ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
#endif
}
vector<int>v;
int n, m, k;
void biuld(int n, int m)
{
    v.clear();
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        if (i < 3)
            v[i] = i + 1;
        else
            v[i] = (v[i - 1] + v[i - 2] + v[i - 3]) % m + 1;

    }
}
int main()
{

    nGu();
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case " << i << ": ";
        cin >> n >> m >> k;
        biuld(n, m);
        map<int, int>con;
        int l = 0, r = 0,ans=INT_MAX;
        while (l < n) {
            while (r < n&&sz(con)<k)
            {
                if (v[r] >= 1 && v[r] <= k)
                    con[v[r]]++;
                r++;
            }
            ans = sz(con) == k ? min(ans, r - l) : ans;
            if (con.find(v[l]) != con.end())
            {
                if (con[v[l]] > 1)
                    con[v[l]]--;
                else
                    con.erase(v[l]);
            }
            l++;
        }
        if (ans > n)
            cout << "sequence nai" << endl;
        else
            cout << ans << endl;

    }
  
}