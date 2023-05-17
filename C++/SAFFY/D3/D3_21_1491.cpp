// 1491

#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		
		int N, A, B;

		cin >> N >> A >> B;

		long long ans = 1000000000;
		for (long long i = 1; i <= sqrt(N); i++) {
			for (long long j = 1; j <= N / i; j++) {
				long long tmp = A * abs(i - j) + (B * (N - i * j));
				ans = min(ans, tmp);
			}
		}

		cout << "#" << test_case << " " << ans << "\n";
	}

	return 0;
}