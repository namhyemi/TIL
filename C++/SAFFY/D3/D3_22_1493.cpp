// 1493

#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>

#define X first
#define Y second

using namespace std;

pair<int, int> T1;
pair<int, int> T2;
pair<int, int> T3;

void calculator(pair<int,int> &T, int num){

	int n = 1;
	while(num > n){
		num -= n;
		n++;
	}

	T.X = n - (num-1);
	T.Y = 1 + (num-1);
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for(int test_case = 1; test_case <= T; test_case++){

		int P,Q;
		cin >> P >> Q;

		calculator(T1, P);
		calculator(T2, Q);

		T3.X = T1.X + T2.X;
		T3.Y = T1.Y + T2.Y;

		int ans = T3.Y;
		int check = T3.X + T3.Y - 1;
		while(check > 0){
			check--;
			ans += check;
		}

		cout << "#" << test_case << " " << ans << "\n";
	}
	return 0;
}
