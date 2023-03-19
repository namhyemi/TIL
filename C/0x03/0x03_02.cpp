// https://www.acmicpc.net/problem/1475
// 1475. ���ȣ

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, x, num[9] = {};

    cin >> a;

    while(a>0)
    {
        x = a%10;
        if(x == 6 || x == 9) num[6]++;
        else num[x]++;
        a = a/10;
    }
    num[6] = num[6]/2 + num[6]%2;
    
    cout << *max_element(num, num+9) << "\n";
}

// *max_element() 


// int main() {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
  
//   int N, a[10] = {}, ans = 0;
//   cin >> N;
  
//   // �ڸ��� ����
//   while(N){
//     a[N%10]++;
//     N /= 10;
//   }

//   for(int i = 0; i < 10; i++){
//     if(i == 6 || i == 9) continue;
//     ans = max(ans, a[i]);
//   }
//   // (a[6]+a[9])/2�� �ø��� ���� 6, 9�� ���� �ʿ��� ��Ʈ�� ���̹Ƿ� (a[6]+a[9]+1)/2�� ���
//   ans = max(ans, (a[6]+a[9]+1)/2);
//   cout << ans;
// }