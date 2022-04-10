#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x;
	cin >> n >> x;
	// prefix sums
	vector<int> sum(n);
	int temp;
	cin >> temp;
	sum[0] = temp;
	for (int i = 1; i < n; i++) {
		cin >> temp;
		sum[i] = sum[i - 1] + temp;
	}
	// two pointers
	int a = 0, b = 0;
	int cnt = 0;
	while (a < n && b < n) {
		int subSum = sum[b] - (a > 0 ? sum[a - 1] : 0);
		if (subSum == x) {
			cnt++;
			a++;
			b++;
		} else if (subSum > x) {
			a++;
		} else {
			b++;
		}
	}

	cout << cnt;
	return 0;
}
