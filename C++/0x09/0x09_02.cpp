// https://www.acmicpc.net/problem/10026
// 10026번. 적록색약

#include<bits/stdc++.h>

using namespace std;

#define X first 
#define Y second

string board[105];
int vit[105][105];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n;

void BFS(int i, int j, char ch){
    queue<pair<int,int>> Q;
    vit[i][j] = 1;
    Q.push({i,j});
    while(!Q.empty()){
        pair<int,int> pos = Q.front(); Q.pop();
        for(int k=0; k < 4; k++){
            int mx = pos.X + dx[k];
            int my = pos.Y + dy[k];

            if(mx < 0 || my < 0 || mx >= n || my >= n) continue;
            if(ch =='R'){
                if(vit[mx][my] != 0 || board[mx][my] == 'B' || board[mx][my] == 'G') continue;
            }
            else if(ch =='G'){        
                if(vit[mx][my] != 0 || board[mx][my] == 'R' || board[mx][my] == 'B') continue;
            }
            else if(ch =='B'){
                if(vit[mx][my] != 0 || board[mx][my] == 'R' || board[mx][my] == 'G') continue;
            }
            vit[mx][my] = 1;
            Q.push({mx,my});
        }
    }
}

void BFS2(int i, int j, char ch){
    queue<pair<int,int>> Q;
    vit[i][j] = 1;
    Q.push({i,j});
    while(!Q.empty()){
        pair<int,int> pos = Q.front(); Q.pop();
        for(int k=0; k < 4; k++){
            int mx = pos.X + dx[k];
            int my = pos.Y + dy[k];

            if(mx < 0 || my < 0 || mx >= n || my >= n) continue;
            if(ch=='R'){
                if(vit[mx][my] != 0 || board[mx][my] == 'B') continue;
            }
            else if(ch=='B'){
                if(vit[mx][my] != 0 || board[mx][my] == 'R' || board[mx][my] == 'G') continue;
            }
            vit[mx][my] = 1;
            Q.push({mx,my});
        }
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0; i < n; i++){
        cin >> board[i];
    }

    int eye_RGB = 0, eye_RG = 0;

    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            if(vit[i][j] == 0){ 
                if(board[i][j] == 'R'){ 
                    BFS(i, j, 'R');
                    eye_RGB++;
                }
                else if(board[i][j] == 'G'){
                    BFS(i, j, 'G');
                    eye_RGB++;
                }
                else if(board[i][j] == 'B'){
                    BFS(i, j, 'B');
                    eye_RGB++;
                }
                else;
            }
        }
    }
    
    fill(&vit[0][0], &vit[n][n], 0);
    
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            if(vit[i][j] == 0){ 
                if(board[i][j] == 'R' || board[i][j] == 'G'){ 
                    BFS2(i, j, 'R');
                    eye_RG++;
                }
                else if(board[i][j] == 'B'){
                    BFS2(i, j, 'B');
                    eye_RG++;
                }
                else;
            }
        }
    }
    cout << eye_RGB << " " << eye_RG << "\n";
}

// 실수 : 변수 잘못 사용 (pos.Y 쳐야하는데 pos.X 침)
// 실수 : if문 중괄호 사용하기