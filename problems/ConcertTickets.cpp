#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <algo/debug.h>
#endif

struct cmp {
	bool operator() (const int& a, const int& b) const {
		return a > b;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	multiset<int, cmp> tickets;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		tickets.insert(temp);
	}
	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		auto assign = tickets.lower_bound(temp);
		// not found
		if (assign == tickets.end()) {
			cout << -1 << '\n';
			continue;
		}
		// found
		cout << *assign << '\n';
		tickets.erase(assign);
	}

	return 0;
}
