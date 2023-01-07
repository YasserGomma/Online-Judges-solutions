#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define all(v) ((v).begin()), ((v).end())
#define sz(v) v.size()
#define endl "\n"
typedef long long ll;
const int N = 2e5 + 5, M = 1e6+5;
int head[N], nxt[M], to[M], ne, n, vid, m, u, v, Indeg[N], res[N], resSz;


void addEdge(int f, int t) {
	nxt[ne] = head[f];
	to[ne] = t;
	head[f] = ne++;
	Indeg[t]++;
}
void init(int n) {
	memset(head, -1, n * sizeof head[0]);
	memset(Indeg, 0, n * sizeof Indeg[0]);

	ne = 0;
	resSz = 0;
}
void topo()
{
	priority_queue <int> pq;
	for (int i = 0; i < n; i++)
		if (!Indeg[i])
			pq.push(-i);

	while (!pq.empty()) {
		int u = -pq.top();
		pq.pop();
		res[resSz++] = u;
		for (int e = head[u]; ~e; e = nxt[e]) {
			int v = to[e];
			if (!--Indeg[v])
				pq.push(-v);
		}
	}

}


int main()
{
	std::ios_base::sync_with_stdio(0); 
	cin.tie(NULL); cout.tie(NULL);
	while (cin >> n >> m && n && m)
	{
		init(n);
		int u, v;
		while (m--) {
			cin >> u >> v;
			addEdge(--u, --v);
		}
		topo();
		if (resSz != n)
			cout << "IMPOSSIBLE" << endl;
		else
		{
			for (int i = 0; i < n; i++)
			{
				cout << ++res[i] << endl;
			}
		}

	}
	
   
}