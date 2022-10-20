#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <bits/stdc++.h>
#endif

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n;
	cin >> n;
	vector<ll> dp(n + 1);
	
	dp[0] = 1;
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= 6; j++) {
			if (i - j >= 0) {
				dp[i] += dp[i - j];
				dp[i] %= (int)(1e9 + 7);
			}
		}
	}

	cout << dp[n];
	return 0;
}
