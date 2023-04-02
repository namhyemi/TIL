// https://www.acmicpc.net/problem/2667
// 2667번. 단지번호 붙이기

#include<bits/stdc++.h>

#define X first
#define Y second

using namespace std;

string board[30];
int vit[30][30];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){ // 입력받기
        cin >> board[i];
    }

    queue<pair<int,int>> Q;
    vector<int> v;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int cnt = 0;
            if(vit[i][j] == 0 && board[i][j] == '1'){
                vit[i][j] = 1;
                Q.push({i,j});
                cnt++;
            }

            while(!Q.empty()){
                auto pos = Q.front(); Q.pop();
                
                for(int k=0; k < 4; k++){
                    int mx = pos.X + dx[k];
                    int my = pos.Y + dy[k];

                    if(mx < 0 || my < 0 || mx >= n || my >= n) continue;
                    if(vit[mx][my] == 1 || board[mx][my] == '0') continue;

                    vit[mx][my] = 1;
                    Q.push({mx, my});
                    cnt++;
                }
            }
            if(cnt != 0) v.push_back(cnt);
        }
    }
    sort(v.begin(), v.end());
    
    cout << v.size() << "\n";
    for(int i=0; i < v.size(); i++){
        cout << v[i] << "\n";
    }
}

// 실수 : 입력값 형태 고려(띄어쓰기 없음)


