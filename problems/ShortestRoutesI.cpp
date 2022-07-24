#include <algorithm>
#include <cassert>
#include <bitset>
#include <deque>
#include <iostream>
#include <climits>
#include <list>
#include <map>
#include <cmath>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

#define dbg(x) cout<<(#x)<<": "<<(x)<<endl
#define dbglp(x) cout<<(#x)<<":"<<endl;for(auto i:x)cout<<i<<" ";cout<<endl
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, m;
	cin >> n >> m;
	vector<vector<pair<ll, ll>>> adj(n);
	vector<ll> dist(n);
	vector<bool> vis(n);
	for (ll i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		adj[a].push_back(make_pair(b, c));
	}

	priority_queue<pair<ll, ll>> q;
	for (ll i = 1; i < n; i++) dist[i] = 1e18;
	q.push(make_pair(0, 0));
	while (!q.empty()) {
		ll node = q.top().second;
		q.pop();
		if (vis[node]) continue;
		vis[node] = true;
		for (auto i : adj[node]) {
			ll x = i.first, w = i.second;
			if (dist[node] + w < dist[x]) {
				dist[x] = dist[node] + w;
				q.push(make_pair(-dist[x], x));
			}
		}
	}

	for (ll i = 0; i < n; i++) cout << dist[i] << " ";
	return 0;
}
