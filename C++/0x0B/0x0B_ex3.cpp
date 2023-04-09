// https://www.acmicpc.net/problem/1074
// 1074��. Z

// �ٽ� Ǯ���

#include<bits/stdc++.h>

using namespace std;

int cnt = -1;
int N, R, C;

int FindVis(int a, int b, int n){
    if(n==0) return 0;
    int half = 1 << (n-1);

    if(a < half && b < half) return FindVis(a, b, n-1); // 1 ��и�
    if(a < half && b >= half) return half * half + FindVis(a, b-half, n-1); // 2 ��и�
    if(a >= half && b < half) return 2 * half * half + FindVis(a-half, b, n-1); // 3 ��и�
    return 3 * half * half + FindVis(a-half, b-half, n-1); // 4 ��и�
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> R >> C;
    
    cout << FindVis(R, C, N);
}


/*
void FindVis(int a, int b, int n){ // a,b�� ������ġ(0,0)
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
// �Ǽ� : ���ϰ��� int�� ��쿡�� return ; ��� �Ұ���
// �Ǽ� : �ι� �湮�ϴ� ��Ȳ �߻� (cnt++ ���� ����� �ϴ°�)

// Ʋ�� ���� : �ð� �ʰ�