#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(v) ((v).begin()), ((v).end())
#define sz(v) v.size()
#define endl "\n"
vector<int>color;
vector<vector<int>>adj;
int cl, same;
void dfs(int u,int par)
{
    same &= (color[u] == cl);
	for(auto it:adj[u])
	{
        if (it != par)
            dfs(it, u);
	}
	
}
bool can(int u)
{
    int _ = 1;
	for(auto it:adj[u])
	{
        cl = color[it];
        same = 1;
        dfs(it, u);
        _ &= same;
		
	}
    return _;
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    adj= vector<vector<int>>(n);
	for(int i=1;i<n;i++)
	{
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
	}

    color= vector<int>(n);
    set<int>st;
    for (int i = 0; i < n; i++)
        cin >> color[i],st.insert(color[i]);

    if (sz(st) == 1)
        return cout <<"YES" <<endl<<1 , 0;

	
    int r1 = 0, r2 = 0;
    for (int i = 0; i < n; i++) {
        for (auto it : adj[i]) {
            if (color[i] != color[it])
            {
                r1 = i, r2 = it;
                break;
            }
        }
    }
   // cout << r1 << " " << r2 << endl;
    if (can(r1))
        cout << "YES" << endl << ++r1;
    else if (can(r2))
        cout << "YES" << endl << ++r2;
    else
        cout << "NO" << endl;
	

	

}