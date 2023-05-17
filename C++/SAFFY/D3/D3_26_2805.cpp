// 2805

#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>

using namespace std;

string board[50];

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for(int test_case = 1; test_case <= T; test_case++){

		int N;
		cin >> N;

		for(int i=0; i<N; i++){
			cin >> board[i];
		}

		int ans = 0;

		for(int i=0; i < N/2; i++){
			int st = N/2 - i;
			int en = N/2 + i;
			for(int j = st; j <= en; j++){
				ans += board[i][j] - '0';
				ans += board[N-1-i][j] - '0';
			}
		}

		for(int i=0; i < N; i++){
			ans += board[N/2][i] - '0';
		}

		cout << "#" << test_case << " " << ans << "\n";
	}
}