// https://www.acmicpc.net/problem/15683
// 15683��. ����

#include<bits/stdc++.h>

#define X first 
#define Y second

using namespace std;

int min_cnt= 100000;
int width, height;
int user_arr[10][10];
vector<pair<int,int>> CCTV_arr; // CCTV ��ġ ����
vector<int> CCTV_cnt_arr; // CCTV ȸ�� Ƚ��

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

// ����� �Է�(�� ����) ����
void UserInputuser_arr(int x, int y){
    cin >> user_arr[x][y];
    return;
}
// CCTV ��ġ ����
void UserInputCCTV_arr(int x,int y){
    if(user_arr[x][y] != 0 && user_arr[x][y] != 6) 
        CCTV_arr.push_back({x,y});
    return;
}
// CCTV ȸ�� Ƚ�� ����
void UserInputCCTV_cnt_arr(int x, int y){
    if(user_arr[x][y] == 1) CCTV_cnt_arr.push_back(4);
    else if(user_arr[x][y] == 2) CCTV_cnt_arr.push_back(2);
    else if(user_arr[x][y] == 3) CCTV_cnt_arr.push_back(4);
    else if(user_arr[x][y] == 4) CCTV_cnt_arr.push_back(4);
    else if(user_arr[x][y] == 5) CCTV_cnt_arr.push_back(1);
    return ;
}
// �Է� �ޱ�
void UserInput(){ 
    cin >> height >> width ; // �� ����, ���� ��
    
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            UserInputuser_arr(i,j);
            UserInputCCTV_arr(i,j);
            UserInputCCTV_cnt_arr(i,j);
        }
    }
}

// �̹� ������� ���� ����(0~6)
// ���� ���� üũ
void DirectionN(int start_X, int start_Y, int n){ 
    for(int i=start_X-1; i >= 0; i--){ // �������� ������
        if(user_arr[i][start_Y] == 6) return; // �� �߽߰� ����
        else if(user_arr[i][start_Y] == 0) user_arr[i][start_Y] = 7+n; // �� �����̸� �ش� CCTV ����(+7)�� ä��
        else if(user_arr[i][start_Y] == 7+n) user_arr[i][start_Y] = 0; // �� �����̸� �ش� 0���� ä��
    }
}
// ���� ���� üũ
void DirectionS(int start_X, int start_Y, int n){ 
    for(int i=start_X+1; i < height; i++){ // �������� ������
        if(user_arr[i][start_Y] == 6) return; // �� �߽߰� ����
        else if(user_arr[i][start_Y] == 0) user_arr[i][start_Y] =  7+n; // �� �����̸� �ش� CCTV ����(+7)�� ä��
        else if(user_arr[i][start_Y] == 7+n) user_arr[i][start_Y] =  0; // �� �����̸� �ش� 0���� ä�� 
    }
}
// ���� ���� üũ
void DirectionW(int start_X, int start_Y, int n){ 
    for(int i=start_Y-1; i >= 0; i--){ // �������� ������
        if(user_arr[start_X][i] == 6) return; // �� �߽߰� ����
        else if(user_arr[start_X][i] == 0) user_arr[start_X][i] =  7+n; // �� �����̸� �ش� CCTV ����(+7)�� ä��
        else if(user_arr[start_X][i] == 7+n) user_arr[start_X][i] =  0; // �� �����̸� �ش� 0���� ä�� 
    }
}
// ���� ���� üũ
void DirectionE(int start_X, int start_Y, int n){ 
    for(int i=start_Y+1; i < width; i++){ // �������� ������
        if(user_arr[start_X][i] == 6) return; // �� �߽߰� ����
        else if(user_arr[start_X][i] == 0) user_arr[start_X][i] =  7+n; // �� �����̸� �ش� CCTV ����(+7)�� ä��
        else if(user_arr[start_X][i] == 7+n) user_arr[start_X][i] =  0; // �� �����̸� �ش� 0���� ä�� 
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

void CCTV_one(int n, int i){ // 1������ CCTV (���� ����)
    if(i==0) CallDirectionN(n);
    else if(i==1) CallDirectionS(n);
    else if(i==2) CallDirectionE(n);
    else if(i==3) CallDirectionW(n); 
}
void CCTV_two(int n, int i){ // 2������ CCTV (���� ����)
    if(i==0){ CallDirectionN(n); CallDirectionS(n); }  // ��, ��
    else if(i==1){ CallDirectionE(n); CallDirectionW(n); } // ��, ��
}
void CCTV_three(int n, int i){ // 3������ CCTV (���� ����)
    if(i==0){ CallDirectionN(n); CallDirectionE(n); } // ��, ��
    else if(i==1){ CallDirectionE(n); CallDirectionS(n); } // ��, ��
    else if(i==2){ CallDirectionS(n); CallDirectionW(n); } // ��, �� 
    else if(i==3){ CallDirectionW(n); CallDirectionN(n); }  // ��, ��    
}
void CCTV_four(int n, int i){ // 4������ CCTV (������)
    if(i==0){ CallDirectionN(n); CallDirectionE(n); CallDirectionS(n);} // ��,��,��
    else if(i==1){ CallDirectionE(n); CallDirectionS(n); CallDirectionW(n);} // ��,��,��
    else if(i==2){ CallDirectionS(n);CallDirectionW(n);CallDirectionN(n);} // ��,��,��
    else if(i==3){ CallDirectionW(n); CallDirectionN(n); CallDirectionE(n);}  // ��,��,��  
}
void CCTV_five(int n, int i){ // 5������ CCTV (�� ����)
    if(i==0){ CallDirectionN(n); CallDirectionE(n); CallDirectionS(n);CallDirectionW(n);}// ��,��,��,��
}

// CCTV ��ȣ Ȯ��
void CheckCCTVNumber(int CCTVnumber, int n, int i){
    if(CCTVnumber == 1) CCTV_one(n, i);
    else if(CCTVnumber == 2) CCTV_two(n, i);
    else if(CCTVnumber == 3) CCTV_three(n, i);
    else if(CCTVnumber == 4) CCTV_four(n, i);
    else if(CCTVnumber == 5) CCTV_five(n, i);
}

// CCTV ���� ����
void CalCCTVRange(int n, int i){
    CheckCCTVNumber(user_arr[CCTV_arr[n].X][CCTV_arr[n].Y], n, i);
}

// �ּ� �簢���� ���ϱ�
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
    
    for(int i=0; i<CCTV_cnt_arr[n]; i++){ // CCTV ȸ�� ���� ���� ��ŭ �ݺ�
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