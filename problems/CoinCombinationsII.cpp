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

	vector<int> dp(x + 1);
	dp[0] = 1;
	for (auto j : c) {
		for (int i = 1; i <= x; i++) {
			if (i - j >= 0) {
				dp[i] += dp[i - j];
				dp[i] %= (int)(1e9 + 7);
			}
		}
	}

	cout << dp[x];
	return 0;
}
