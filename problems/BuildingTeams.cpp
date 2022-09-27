#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <algo/debug.h>
#endif

bool bipartite = true;
vector<vector<int>> adj;
vector<bool> vis, color;

void dfs(int node, bool lastColor) {
	if (vis[node]) {
		if (color[node] == lastColor) bipartite = false;
		return;
	}
	vis[node] = true;
	color[node] = !lastColor;
	for (auto i : adj[node]) dfs(i, color[node]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	adj.resize(n);
	vis.resize(n);
	color.resize(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		if (!vis[i]) dfs(i, false);
	}

	if (bipartite) {
		for (int i = 0; i < n; i++) {
			cout << color[i] + 1 << " ";
		}
	} else {
		cout << "IMPOSSIBLE";
	}
	return 0;
}
