#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > list;
vector<bool> visited;

void dfs(int n) {
	if (visited[n]) {
		return;
	} else {
		visited[n] = true;
		for (int i : list[n]) {
			if (!visited[i]) {
				dfs(i);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
 
	int n, m;
	cin >> n >> m;

	visited = vector<bool>(n, false);
	list.resize(n);
	for (int i = 0; i < n; i++) {
		list[i] = vector<int>(0);
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		list[a - 1].push_back(b - 1);
		list[b - 1].push_back(a - 1);
	}
	// store all first seen non-connected components
	vector<int> componentFirsts(0);
	visited.resize(n);
	for (int i = 0; i < n; i++) {
		if (visited[i] == false) {
			componentFirsts.push_back(i);
			dfs(i);
		}
	}

	cout << componentFirsts.size() - 1 << "\n";
	for (int i = 0; i < componentFirsts.size() - 1; i++) {
		cout << componentFirsts[i] + 1 << " " << componentFirsts[i + 1] + 1 << "\n";
	}
	return 0;
}
