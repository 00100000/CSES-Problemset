#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, x;
	cin >> n >> x;
	vector<ll> a(n / 2);
	vector<ll> b((n + 1) / 2);
	for (ll i = 0; i < n / 2; i++) cin >> a[i];
	for (ll i = n / 2; i < n; i++) cin >> b[i - n / 2];

	vector<ll> asum;
	for (ll i = 0; i < (1 << n / 2); i++) {
		ll sum = 0;
		for (ll j = 0; j < n / 2; j++) {
			if (i & (1 << j)) sum += a[j];
		}
		asum.push_back(sum);
	}
	sort(asum.begin(), asum.end());
	// check b subset sums with a
	ll ans = 0;
	for (ll i = 0; i < (1 << (n + 1) / 2); i++) {
		ll sum = 0;
		for (ll j = 0; j < (n + 1) / 2; j++) {
			if (i & (1 << j)) sum += b[j];
		}
		int l = lower_bound(asum.begin(), asum.end(), x - sum) - asum.begin();
		int r = upper_bound(asum.begin(), asum.end(), x - sum) - asum.begin();
		ans += r - l;
	}

	cout << ans;
	return 0;
}
