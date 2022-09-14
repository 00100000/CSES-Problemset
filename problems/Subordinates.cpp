#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <algo/debug.h>
#endif

vector<vector<int>> adj;
vector<int> sub;
vector<bool> visited;

int dfs(int node) {
	if (visited[node]) return 0;
	visited[node] = true;
	for (auto i : adj[node]) {
		sub[node]++;
		sub[node] += dfs(i);
	}
	return sub[node];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	adj.resize(n);
	sub.resize(n);
	visited.resize(n);
	for (int i = 1; i < n; i++) {
		int temp;
		cin >> temp;
		temp--;
		adj[temp].push_back(i);
	}
	dfs(0);
	for (int i = 0; i < n; i++) cout << sub[i] << " ";

	return 0;
}
