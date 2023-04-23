// https://www.acmicpc.net/problem/10989
// 10989��. �� �����ϱ�3

#include<bits/stdc++.h>

using namespace std;

int number[10000];

void InputUserDate(){
    int cnt, num;
    cin >> cnt;
    while(cnt--){
        cin >> num;
        number[num-1]++;
    }
}

void OutputData(){
    for(int i=0; i < 10000; i++){
        while(number[i]--){
            cout << i+1 << "\n";
        }
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    InputUserDate();
    OutputData();
}

// Ʋ�� ���� : �޸� �ʰ� => int�� õ������ �� 40MB �޸� ���(https://www.acmicpc.net/board/view/26132)
// Ʋ�� ���� : �ð� �ʰ� => ios::sync_with_stdio(0);, cin.tie(0); (https://www.acmicpc.net/problem/15552)
// Ʋ�� ���� : ���� �Ǽ� => 10000 ����