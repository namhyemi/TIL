// https://www.acmicpc.net/problem/9466
// 9466��. �� ������Ʈ

#include<bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int team[100005]; // �� ��ȣ
int vit[100005]; // �� �Ἲ ����

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
            if(team[i] == -1){ // �鸰 �� ������ üũ
                Q.push({i, v[i]-1});
                team[i] = team_num; // �� ��ȣ
                vit[i] = 0;

                while(!Q.empty()){
                    auto pos = Q.front(); Q.pop();
                    if(pos.X == pos.Y){ // ȥ�� �� �Ἲ
                        cnt--;
                        continue;
                    }
                    if(team[pos.Y] == team_num){ // �� �Ἲ
                        cnt = vit[pos.Y]; // ������ ���ܵ� �ο�
                        continue;
                    }
                    if(team[pos.Y] != -1) continue; // �鸰�� �ִ��� üũ

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


// �ٸ� ���
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
//     // �̹� �湮���� ������ �л��� �������� ���
//     if(state[cur] == x){
//       while(state[cur] != CYCLE_IN){
//         state[cur] = CYCLE_IN;
//         cur = arr[cur];
//       }
//       return;
//     }
//     // ���� �湮���� ������ �л��� �������� ���
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
