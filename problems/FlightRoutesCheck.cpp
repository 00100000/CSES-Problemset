#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<vector<int>> revEdges;
vector<bool> visited;

void dfs(int node) {
	if (visited[node]) return;
	visited[node] = true;
	for (int i = 0; i < adj[node].size(); i++) {
		dfs(adj[node][i]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	adj.resize(n, vector<int>(0));
	revEdges.resize(n, vector<int>(0));
	visited.resize(n);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].push_back(b);
		// create an adjacency list where all edges of b are reversed
		revEdges[b].push_back(a);
	}
	// check if you can visit every node from the 0th node
	dfs(0);
	bool visitedAll = true;
	int i = 0;
	for (; i < n; i++) {
		if (!visited[i]) {
			visitedAll = false;
			break;
		}
	}
	if (!visitedAll) {
		cout << "NO" << "\n" << 0 << " " << i;
		return 0;
	}
	// reverse all edges of adjaceny list
	adj = revEdges;
	// reset variables
	for (int j = 0; j < n; j++) visited[j] = false;
	visitedAll = true;
	i = 0;
	// check if you can visit every node from the 0th node
	// if you can wit the edges reversed, the entire graph
	// must be one big cycle of other subcycles, which allows
	// you to get to any airport from any other airport
	dfs(0);
	for (; i < n; i++) {
		if (!visited[i]) {
			visitedAll = false;
			break;
		}
	}
	if (!visitedAll) {
		cout << "NO" << "\n" << i << " " << 0;
		return 0;
	}

	cout << "YES";
	return 0;
}
