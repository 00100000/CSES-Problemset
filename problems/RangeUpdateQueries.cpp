#include <iostream>
#include <vector>
using namespace std;

struct Node {
	long long lo, hi;
	Node* right = nullptr;
	Node* left = nullptr;
	long long lazy = 0, sum = 0;

	Node(long long r_lo, long long r_hi) {
		lo = r_lo;
		hi = r_hi;
	}
	void build(long long r_lo, long long r_hi, vector<long long>& vals) {
		if (vals.size() <= r_hi) return;
		long long m = (hi + lo) / 2;
		if (r_lo == r_hi) {
			sum = vals[r_hi];
			return;
		}
		left = new Node(lo, m);
		right = new Node(m + 1, hi);
		left->build(lo, m, vals);
		right->build(m + 1, hi, vals);
		sum = left->sum + right->sum;
	}
	void increment(long long r_lo, long long r_hi, long long amt) {
		if (r_lo > hi || r_hi < lo) return;
		if (r_lo <= lo && r_hi >= hi) {
			lazy += amt;
			sum += amt * (hi + 1 - lo);
			return;
		}
		push();
		left->increment(r_lo, r_hi, amt);
		right->increment(r_lo, r_hi, amt);
		sum = right->sum + left->sum;
	}
	void push() {
		if (lazy != 0) {
			left->increment(lo, hi, lazy);
			right->increment(lo, hi, lazy);
			lazy = 0;
		}
	}
	long long point(long long pt) {
		if (lo > pt || hi < pt) return 0;
		if (lo == pt && hi == pt) return sum;
		push();
		long long rsum = 0;
		if (left != nullptr) rsum += left->point(pt);
		if (right != nullptr) rsum += right->point(pt);
		return rsum;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q;
	cin >> n >> q;

	vector<long long> vals(n);
	for (int i = 0; i < n; i++) cin >> vals[i];

	Node* st = new Node(0, n - 1);
	st->build(0, n - 1, vals);
	for (int i = 0; i < q; i++) {
		int type;
		cin >> type;
		if (type == 1) {
			int a, b, u;
			cin >> a >> b >> u;
			a--;
			b--;
			st->increment(a, b, u);
		} else {
			int k;
			cin >> k;
			k--;
			cout << st->point(k) << "\n";
		}
	}

	return 0;
}
