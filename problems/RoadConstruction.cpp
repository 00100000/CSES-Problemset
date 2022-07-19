#include <iostream>
#include <vector>
using namespace std;
// disjoint set union
struct DSU {
	vector<int> parent;
	vector<int> size;
	int components;
	int maxSize;

	DSU(int range) {
		parent.resize(range);
		size.resize(range);
		for (int i = 0; i < range; i++) {
			parent[i] = i;
			size[i] = 1;
		}
		maxSize = 1;
		components = range;
	}
	int find(int node) {
		if (parent[node] == node) return node;
		return parent[node] = find(parent[node]);
	}
	bool join(int a, int b) {
		a = find(a);
		b = find(b);
		if (a == b) return false;
		// make a < b to join smaller set into larger set
		if (size[a] < size[b]) {
			int temp = a;
			a = b;
			b = temp;
		}
		parent[b] = a;
		size[a] += size[b];
		size[b] = size[a];

		components--;
		maxSize = max(maxSize, size[a]);
		return true;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	DSU d(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		d.join(a, b);
		cout << d.components << " " << d.maxSize << "\n";
	}

	return 0;
}
