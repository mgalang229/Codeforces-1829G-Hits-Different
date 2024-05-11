#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ans[2000007];
ll a[1500][1500] = {};
ll cur = 1;

void test_case(int& tc) {
	int n;
	cin >> n;
	cout << ans[n] << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	// pre-compute (2D Prefix Sums)
	for (int i = 1; i < 1500; i++) {
		for (int j = i - 1; j >= 1; j--) {
			a[j][i-j] = a[j-1][i-j] + a[j][i-j-1] - a[j-1][i-j-1] + cur * cur;
			ans[cur] = a[j][i-j];
			cur++;
		}
	}

	int T = 1;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		test_case(tc);
	}
}
