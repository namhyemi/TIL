// https://www.acmicpc.net/problem/13549
// 13549번. 숨바꼭질3

// 다시 풀기

#include <bits/stdc++.h>
using namespace std;

const int LMT = 100001;
int board[LMT+2];
int sis, bro;
queue<int> Q;
void teleport(int num) {
  int tmp = num;
  if (!tmp) return;
  while (tmp < LMT && !board[bro]) {
    if (!board[tmp]) {
      board[tmp] = board[num];
      Q.push(tmp);
      if (tmp == bro) return;
    }
    tmp <<= 1;
  }
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> sis >> bro;
  board[sis] = 1;
  Q.push(sis);
  teleport(sis);
  while (!board[bro]) {
    int v = Q.front(); Q.pop();
    vector<int> nvLst = { v + 1, v - 1 };
    for (int nv : nvLst) {
      if (nv < 0 || LMT <= nv) continue;
      if (board[nv]) continue;
      board[nv] = board[v] + 1;
      Q.push(nv);
      teleport(nv);
    }
  }
  cout << board[bro]-1;
}



// #include<bits/stdc++.h>

// using namespace std;

// int arr[200000];
// int dx[3] = {-1,1,2};

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     queue<int> Q;
//     int game_start, game_end;
//     cin >> game_start >> game_end;

//     arr[game_start] = 1;
//     Q.push(game_start);

//     while(!Q.empty()){
//         int pos = Q.front(); Q.pop();
//         int tmp;
//         if(pos == game_end){
//             cout << arr[pos]-1 << "\n";
//             return 0;
//         }

//         for(int i=0; i < 3; i++){
//             if(dx[i]==2) tmp = pos * 2;
//             else tmp = pos + dx[i];

//             if(tmp < 0 || tmp > 200000) continue;
//             if(arr[tmp] != 0) continue;

//             if(dx[i]==2) arr[tmp] = arr[pos] ;
//             else arr[tmp] = arr[pos] + 1;
//             Q.push(tmp);
//         }
//     }
// }


