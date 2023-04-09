// https://www.acmicpc.net/problem/9663
// 9663번. N-Queen

#include<bits/stdc++.h>

using namespace std;

int N, cnt=0;
bool isused_y[20];
bool isused_cross_plus[30];
bool isused_cross_minus[30];

void func(int x){
    if(x==N){ // 마지막 행까지 도착
        cnt++;
        return;
    }

    for(int y=0; y < N; y++){
        if(!isused_y[y] && !isused_cross_plus[x+y] && !isused_cross_minus[x-y+N-1]){ // 조건(대각선, 가로, 세로 겹치지 않음)에 부합한 경우
            isused_y[y] = true;
            isused_cross_plus[x+y] = true;
            isused_cross_minus[x-y+N-1] = true;
            func(x+1);
            isused_y[y] = false;
            isused_cross_plus[x+y] = false;
            isused_cross_minus[x-y+N-1] = false;            
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    func(0);
    cout << cnt;
}

/*
- 시간 복잡도 : 열만 가지고 보면 O(N!) N = 14일 때 애매해짐 실제로는 꽤 빠름. (가지치기) => 가늠하기 어려움
  N이 많이 작아서 백트래킹일거 같은 경우는 가장 시간이 많이 걸릴거 같은 예제를 돌려봐서 시간초과 나는지 확인
  
- Release 모드 검색
*/