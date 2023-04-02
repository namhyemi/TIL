// https://www.acmicpc.net/problem/9466
// 9466번. 텀 프로젝트

#include<bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int team[100005]; // 팀 번호
int vit[100005]; // 팀 결성 순번

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    cin >> num;

    while(num--){
        int student_num, sum = 0, team_num = 0;
        cin >> student_num;

        int n;
        vector<int> v;
        for(int i=0; i < student_num; i++){
            cin >> n;
            v.push_back(n);
        }
        fill(team, team+student_num, -1);

        queue<pair<int,int>> Q;
        for(int i=0; i < student_num; i++){
            int cnt = 1;
            if(team[i] == -1){ // 들린 적 없는지 체크
                Q.push({i, v[i]-1});
                team[i] = team_num; // 팀 번호
                vit[i] = 0;

                while(!Q.empty()){
                    auto pos = Q.front(); Q.pop();
                    if(pos.X == pos.Y){ // 혼자 팀 결성
                        cnt--;
                        continue;
                    }
                    if(team[pos.Y] == team_num){ // 팀 결성
                        cnt = vit[pos.Y]; // 팀에서 제외된 인원
                        continue;
                    }
                    if(team[pos.Y] != -1) continue; // 들린적 있는지 체크

                    Q.push({pos.Y,v[pos.Y]-1});
                    team[pos.Y] = team_num;
                    vit[pos.Y] = vit[pos.X] + 1;
                    cnt++;
                    
                }
                sum += cnt;
                team_num++;
            }
        }
        cout << sum << "\n";
    }
}


// 다른 방법
// #include <bits/stdc++.h>
// using namespace std;

// int arr[100005];
// int n;
// int state[100005]; 

// const int NOT_VISITED = 0;
// const int CYCLE_IN = -1;

// void run(int x){
//   int cur = x;
//   while(true){
//     state[cur] = x;
//     cur = arr[cur];
//     // 이번 방문에서 지나간 학생에 도달했을 경우
//     if(state[cur] == x){
//       while(state[cur] != CYCLE_IN){
//         state[cur] = CYCLE_IN;
//         cur = arr[cur];
//       }
//       return;
//     }
//     // 이전 방문에서 지나간 학생에 도달했을 경우
//     else if(state[cur] != 0) return;
//   }
// }

// int main(void){
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   int t;
//   cin >> t;
//   while(t--){
//     cin >> n;
//     fill(state+1, state+n+1, 0);
//     for(int i = 1; i <= n; i++)
//       cin >> arr[i];
//     int ans = 0;
//     for(int i = 1; i <= n; i++){
//       if(state[i] == NOT_VISITED) run(i);
//     }
//     int cnt = 0;
//     for(int i = 1; i <= n; i++){
//       if(state[i] != CYCLE_IN) cnt++;
//     }
//     cout << cnt << '\n';
//   }
// }
