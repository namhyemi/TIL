// https://www.acmicpc.net/problem/15683
// 15683번. 감시

#include<bits/stdc++.h>

#define X first 
#define Y second

using namespace std;

int min_cnt= 100000;
int width, height;
int user_arr[10][10];
vector<pair<int,int>> CCTV_arr; // CCTV 위치 정보
vector<int> CCTV_cnt_arr; // CCTV 회전 횟수

/*
void ViewUserArrStatus(){
    cout << "\n";
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            cout << user_arr[i][j] << " " ;
        } cout << "\n";
    } 
}
*/

// 사용자 입력(방 정보) 저장
void UserInputuser_arr(int x, int y){
    cin >> user_arr[x][y];
    return;
}
// CCTV 위치 저장
void UserInputCCTV_arr(int x,int y){
    if(user_arr[x][y] != 0 && user_arr[x][y] != 6) 
        CCTV_arr.push_back({x,y});
    return;
}
// CCTV 회전 횟수 저장
void UserInputCCTV_cnt_arr(int x, int y){
    if(user_arr[x][y] == 1) CCTV_cnt_arr.push_back(4);
    else if(user_arr[x][y] == 2) CCTV_cnt_arr.push_back(2);
    else if(user_arr[x][y] == 3) CCTV_cnt_arr.push_back(4);
    else if(user_arr[x][y] == 4) CCTV_cnt_arr.push_back(4);
    else if(user_arr[x][y] == 5) CCTV_cnt_arr.push_back(1);
    return ;
}
// 입력 받기
void UserInput(){ 
    cin >> height >> width ; // 방 가로, 세로 값
    
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            UserInputuser_arr(i,j);
            UserInputCCTV_arr(i,j);
            UserInputCCTV_cnt_arr(i,j);
        }
    }
}

// 이미 사용중인 숫자 제외(0~6)
// 북쪽 방향 체크
void DirectionN(int start_X, int start_Y, int n){ 
    for(int i=start_X-1; i >= 0; i--){ // 북쪽으로 움직임
        if(user_arr[i][start_Y] == 6) return; // 벽 발견시 종료
        else if(user_arr[i][start_Y] == 0) user_arr[i][start_Y] = 7+n; // 빈 공간이면 해당 CCTV 순서(+7)로 채움
        else if(user_arr[i][start_Y] == 7+n) user_arr[i][start_Y] = 0; // 빈 공간이면 해당 0으로 채움
    }
}
// 남쪽 방향 체크
void DirectionS(int start_X, int start_Y, int n){ 
    for(int i=start_X+1; i < height; i++){ // 남쪽으로 움직임
        if(user_arr[i][start_Y] == 6) return; // 벽 발견시 종료
        else if(user_arr[i][start_Y] == 0) user_arr[i][start_Y] =  7+n; // 빈 공간이면 해당 CCTV 순서(+7)로 채움
        else if(user_arr[i][start_Y] == 7+n) user_arr[i][start_Y] =  0; // 빈 공간이면 해당 0으로 채움 
    }
}
// 서쪽 방향 체크
void DirectionW(int start_X, int start_Y, int n){ 
    for(int i=start_Y-1; i >= 0; i--){ // 서쪽으로 움직임
        if(user_arr[start_X][i] == 6) return; // 벽 발견시 종료
        else if(user_arr[start_X][i] == 0) user_arr[start_X][i] =  7+n; // 빈 공간이면 해당 CCTV 순서(+7)로 채움
        else if(user_arr[start_X][i] == 7+n) user_arr[start_X][i] =  0; // 빈 공간이면 해당 0으로 채움 
    }
}
// 동쪽 방향 체크
void DirectionE(int start_X, int start_Y, int n){ 
    for(int i=start_Y+1; i < width; i++){ // 동쪽으로 움직임
        if(user_arr[start_X][i] == 6) return; // 벽 발견시 종료
        else if(user_arr[start_X][i] == 0) user_arr[start_X][i] =  7+n; // 빈 공간이면 해당 CCTV 순서(+7)로 채움
        else if(user_arr[start_X][i] == 7+n) user_arr[start_X][i] =  0; // 빈 공간이면 해당 0으로 채움 
    }
}

void CallDirectionN(int n){
    DirectionN(CCTV_arr[n].X, CCTV_arr[n].Y, n);
}
void CallDirectionS(int n){
    DirectionS(CCTV_arr[n].X, CCTV_arr[n].Y, n);
}
void CallDirectionE(int n){
    DirectionE(CCTV_arr[n].X, CCTV_arr[n].Y, n);
}
void CallDirectionW(int n){
    DirectionW(CCTV_arr[n].X, CCTV_arr[n].Y, n);
}

void CCTV_one(int n, int i){ // 1번종류 CCTV (한쪽 방향)
    if(i==0) CallDirectionN(n);
    else if(i==1) CallDirectionS(n);
    else if(i==2) CallDirectionE(n);
    else if(i==3) CallDirectionW(n); 
}
void CCTV_two(int n, int i){ // 2번종류 CCTV (양쪽 방향)
    if(i==0){ CallDirectionN(n); CallDirectionS(n); }  // 북, 남
    else if(i==1){ CallDirectionE(n); CallDirectionW(n); } // 동, 서
}
void CCTV_three(int n, int i){ // 3번종류 CCTV (직각 방향)
    if(i==0){ CallDirectionN(n); CallDirectionE(n); } // 남, 동
    else if(i==1){ CallDirectionE(n); CallDirectionS(n); } // 동, 남
    else if(i==2){ CallDirectionS(n); CallDirectionW(n); } // 남, 서 
    else if(i==3){ CallDirectionW(n); CallDirectionN(n); }  // 서, 북    
}
void CCTV_four(int n, int i){ // 4번종류 CCTV (세방향)
    if(i==0){ CallDirectionN(n); CallDirectionE(n); CallDirectionS(n);} // 북,동,남
    else if(i==1){ CallDirectionE(n); CallDirectionS(n); CallDirectionW(n);} // 동,남,서
    else if(i==2){ CallDirectionS(n);CallDirectionW(n);CallDirectionN(n);} // 남,서,북
    else if(i==3){ CallDirectionW(n); CallDirectionN(n); CallDirectionE(n);}  // 서,북,동  
}
void CCTV_five(int n, int i){ // 5번종류 CCTV (네 방향)
    if(i==0){ CallDirectionN(n); CallDirectionE(n); CallDirectionS(n);CallDirectionW(n);}// 북,동,남,서
}

// CCTV 번호 확인
void CheckCCTVNumber(int CCTVnumber, int n, int i){
    if(CCTVnumber == 1) CCTV_one(n, i);
    else if(CCTVnumber == 2) CCTV_two(n, i);
    else if(CCTVnumber == 3) CCTV_three(n, i);
    else if(CCTVnumber == 4) CCTV_four(n, i);
    else if(CCTVnumber == 5) CCTV_five(n, i);
}

// CCTV 감시 구역
void CalCCTVRange(int n, int i){
    CheckCCTVNumber(user_arr[CCTV_arr[n].X][CCTV_arr[n].Y], n, i);
}

// 최소 사각지대 구하기
int CalMinCnt(){ 
    // TestUserArr();
    int cnt = 0;
    for(int i=0; i<height; i++)
        for(int j=0; j<width; j++)
            if(user_arr[i][j] == 0)
                cnt++;
    return min(cnt, min_cnt); 
}

void BackTracking(int n){
    if(n == CCTV_arr.size()){ // base condition
        min_cnt = CalMinCnt();
        return;
    }
    
    for(int i=0; i<CCTV_cnt_arr[n]; i++){ // CCTV 회전 방향 개수 만큼 반복
        CalCCTVRange(n,i);
        BackTracking(n+1);
        CalCCTVRange(n,i);
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    UserInput();
    BackTracking(0);

    cout << min_cnt << "\n";
}