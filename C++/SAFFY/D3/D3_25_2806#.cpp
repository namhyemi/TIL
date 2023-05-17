// 2806

#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>

using namespace std;

int board[15][15];
int num;
int ans;

int isused_y[20];
int isused_cross1[20];
int isused_cross2[20];

void func(int n){
	if(num == n){
		ans++;
		return;
	}

	for(int i=0; i < num; i++){
		if(isused_y[i] || isused_cross1[n+i] || isused_cross2[n-i+num-1]){
			continue;
		}
		isused_y[i] = 1;
		isused_cross1[n+i] = 1;
		isused_cross2[n-i+num-1] = 1;
		func(n+1);
		isused_y[i] = 0;
		isused_cross1[n+i] = 0;
		isused_cross2[n-i+num-1] = 0;		
	}
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for(int test_case = 1; test_case <= T; test_case++){

		cin >> num;

		ans = 0;	
		memset(board, 0, sizeof(board));

		func(0);

		cout << "#" << test_case << " " << ans << "\n";
	}
}