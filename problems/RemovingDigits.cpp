#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <algo/debug.h>
#endif

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> dp(n + 1);
	for (int i = 1; i <= n; i++) {
		string nstr = to_string(i);
		dp[i] = 1e6;
		for (int j = 0; j < (int)nstr.size(); j++) {
			dp[i] = min(dp[i], dp[i - (nstr.at(j) - 48)] + 1);
		}
	}

	cout << dp[n];
	return 0;
}
