#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <algo/debug.h>
#endif

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x;
	cin >> n >> x;
	vector<int> c(n);
	for (int i = 0; i < n; i++) cin >> c[i];

	vector<int> val(x + 1);
	for (int i = 1; i <= x; i++) {
		val[i] = 1e9;
		for (auto j : c) {
			if (i - j >= 0) {
				val[i] = min(val[i], val[i - j] + 1);
			}
		}
	}

	cout << (val[x] == 1e9 ? -1 : val[x]);
	return 0;
}
