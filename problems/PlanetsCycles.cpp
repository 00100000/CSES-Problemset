#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <algo/debug.h>
#endif

vector<vector<int>> backward;
vector<int> cycle;
vector<bool> inCycle;
vector<bool> vis;

void dfs(int node, int len) {
	if (vis[node]) return;
	vis[node] = true;
	cycle[node] = len;
	for (auto i : backward[node]) {
		if (!inCycle[i]) dfs(i, len + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> adj(n);
	backward.resize(n);
	cycle.resize(n);
	vis.resize(n);
	inCycle.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> adj[i];
		adj[i]--;
		backward[adj[i]].push_back(i);
	}

	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			int a = i, b = i;
			do {
				a = adj[a];
				b = adj[adj[b]];
			} while (a != b);
			// find cycle length and mark off cycle
			int cycleLen = 0;
			do {
				a = adj[a];
				inCycle[a] = true;
				cycleLen++;
			} while (a != b);
			// mark off connected component, and label cycle "tails"
			do {
				a = adj[a];
				dfs(a, cycleLen);
			} while (a != b);
		}
	}

	for (int i = 0; i < n; i++) cout << cycle[i] << ' ';
	return 0;
}
