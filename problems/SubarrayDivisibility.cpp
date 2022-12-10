#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <algo/debug.h>
#endif

typedef long long ll;

ll n;

ll floorMod(ll x) { return (x % n + n) % n; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	vector<ll> a(n + 1);
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] = floorMod(a[i]);
	}
	// prefix sums
	for (ll i = 1; i <= n; i++) {
		a[i] += a[i - 1];
		a[i] %= n;
	}

	vector<ll> m(n + 1);
	for (ll i = 1; i <= n; i++) m[a[i]]++;
	// two prefixes of the same number over mod create a
	// unique subarray divisible by n (= 0 over mod n)
	ll cnt = 0;
	for (ll i = 0; i <= n; i++) {
		// choose 2 prefixes
		cnt += m[i] * (m[i] - 1) / 2;
	}
	// lone prefixes work for values that already equal 0 (mod n)
	cnt += m[0];

	cout << cnt;
	return 0;
}
