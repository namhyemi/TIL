// https://www.acmicpc.net/problem/1697
// 1697번. 숨바꼭질

#include<bits/stdc++.h>

using namespace std;

int arr[100000];
int dx[3] = {-1,1,2};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<int> Q;
    int game_start, game_end;
    cin >> game_start >> game_end;

    arr[game_start] = 1;
    Q.push(game_start);

    while(!Q.empty()){
        int pos = Q.front(); Q.pop();
        int tmp;
        if(pos == game_end){
            cout << arr[pos]-1 << "\n";
            return 0;
        }

        for(int i=0; i < 3; i++){
            if(dx[i]==2) tmp = pos * 2;
            else tmp = pos + dx[i];

            if(tmp < 0 || tmp > 100000) continue;
            if(arr[tmp] != 0) continue;

            arr[tmp] = arr[pos] + 1;
            Q.push(tmp);
        }
    }
}

// 틀린 이유 : 런타임에러(OutofBounds) - 배열 범위 벗어남.


// 학습
// while(arr[game_end] ==  -1){
//     int pos = Q.front(); Q.pop();
//*     for(int tmp : {pos+1, pos-1, pos*2}){
//         if(tmp < 0 || tmp > 100000) continue;
//         if(arr[tmp] != 0) continue;
//         arr[tmp] = arr[pos] + 1;
//         Q.push(tmp);
//     }
// } cout << arr[game_end];