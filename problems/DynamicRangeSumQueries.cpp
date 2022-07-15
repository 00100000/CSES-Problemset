#include <iostream>
#include <vector>
using namespace std;

long long n, q;
// sparse segment tree
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
		if (n <= r_hi) return;
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
		// disjolong long ranges
		if (r_lo > hi || r_hi < lo) return;
		// check if this Node's range is contained completely in r range
		if (r_lo <= lo && r_hi >= hi) {
			lazy += amt;
			sum += amt * (hi + 1 - lo);
			return;
		}
		// push our lazy value down (useful for query types problem)
		push();
		left->increment(r_lo, r_hi, amt);
		right->increment(r_lo, r_hi, amt);
		sum = right->sum + left->sum;
	}
	void push() {
		if (lazy != 0) {
			// push the value long longo the children
			left->increment(lo, hi, lazy);
			right->increment(lo, hi, lazy);
			lazy = 0;
		}
	}
	long long rangeSum(long long r_lo, long long r_hi) {
		// check if there is no overlap
		if (lo > r_hi || hi < r_lo) return 0;
		// check if completely contained
		if (lo >= r_lo && hi <= r_hi) return sum;
		push();
		long long rsum = 0;
		if (left != nullptr) rsum += left->rangeSum(r_lo, r_hi);
		if (right != nullptr) rsum += right->rangeSum(r_lo, r_hi);
		return rsum;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> q;

	vector<long long> vals(n);
	for (long long i = 0; i < n; i++) cin >> vals[i];

	Node* segtree = new Node(0, n - 1);
	segtree->build(0, n - 1, vals);
	for (long long i = 0; i < q; i++) {
		long long type;
		cin >> type;
		if (type == 1) {
			long long k, u;
			cin >> k >> u;
			k--;
			// update position k to u
			segtree->increment(k, k, u - vals[k]);
			vals[k] = u;
		} else {
			long long a, b;
			cin >> a >> b;
			a--;
			b--;
			// prlong long the sum of values from [a, b]
			cout << segtree->rangeSum(a, b) << "\n";
		}
		//segtree->prlong long(0);
	}

	return 0;
}
