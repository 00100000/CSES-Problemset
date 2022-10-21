#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/stdc++.h>
#endif

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x;
	cin >> n >> x;
	vector<int> c(n);
	for (int i = 0; i < n; i++) cin >> c[i];

	vector<ll> dp(x + 1);
	dp[0] = 1;
	for (int i = 1; i <= x; i++) {
		for (auto j : c) {
			if (i - j >= 0) {
				dp[i] += dp[i - j];
				dp[i] %= (ll)(1e9 + 7);
			}
		}
	}

	cout << dp[x];
	return 0;
}
