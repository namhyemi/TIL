// https://www.acmicpc.net/problem/1074
// 1074번. Z

// 다시 풀어보기

#include<bits/stdc++.h>

using namespace std;

int cnt = -1;
int N, R, C;

int FindVis(int a, int b, int n){
    if(n==0) return 0;
    int half = 1 << (n-1);

    if(a < half && b < half) return FindVis(a, b, n-1); // 1 사분면
    if(a < half && b >= half) return half * half + FindVis(a, b-half, n-1); // 2 사분면
    if(a >= half && b < half) return 2 * half * half + FindVis(a-half, b, n-1); // 3 사분면
    return 3 * half * half + FindVis(a-half, b-half, n-1); // 4 사분면
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> R >> C;
    
    cout << FindVis(R, C, N);
}


/*
void FindVis(int a, int b, int n){ // a,b는 시작위치(0,0)
    if(n == 0){
        cnt++;
        if(a==R && b==C) cout << cnt << "\n";
        return ;
    }
    int k = (1 << (n-1));

    FindVis(a, b, n-1);
    FindVis(a, b+k, n-1);
    FindVis(a+k, b, n-1);
    FindVis(a+k, b+k, n-1);
}
*/
// 실수 : 리턴값이 int인 경우에는 return ; 사용 불가능
// 실수 : 두번 방문하는 상황 발생 (cnt++ 언제 해줘야 하는가)

// 틀린 이유 : 시간 초과