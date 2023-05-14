// https://www.acmicpc.net/problem/1676
// 1676. ���丮�� 0�� ����

#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    cin >> num;

    int mul = 1;
    int result = 0;
    for(int i=1; i<=num; i++){
        mul *= i;
        while(mul % 10 == 0){
            result++;
            mul /= 10;
        }

        if(mul > 1000000){
            mul %= 1000000;
        }
    }

    cout << result << "\n";
}

// �ٸ� �ڵ� : https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x12/solutions/1676.cpp
/*
#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int ans = 0;
  while (n) {
    ans += n / 5;
    n /= 5;
  }
  cout << ans;
}
// 10 = (2X5) -> 5�� ����(2�� ������ �ξ� ����)
// 5, 25(5X5), 125(5X5X5)
*/