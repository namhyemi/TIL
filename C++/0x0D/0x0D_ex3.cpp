// https://www.acmicpc.net/problem/12100
// 12100��. 2048(Easy)

#include<bits/stdc++.h>

using namespace std;

int gameboard[6][25][25];

int move_position[25];
int boardsize;
int max_num = 0;

void InputUesrData(){
    cin >> boardsize;

    for(int i=0; i<boardsize; i++)
        for(int j=0; j<boardsize; j++)
            cin >> gameboard[0][i][j];
}  

void MovePositionArrResetMAX(){
    fill(move_position, move_position+boardsize, boardsize);
}
void MovePositionArrResetMIN(){
    fill(move_position, move_position+boardsize, 0);
}

void MoveUp(int n){
    int check[20];
    memset(check, 0, sizeof(check)); // ���� ���� Ȯ��

    MovePositionArrResetMAX();
    for(int row=0; row<boardsize; row++){
        for(int col=0; col<boardsize; col++){
            if(gameboard[n][row][col]==0){ if(move_position[col] > row){ move_position[col] = row;}} // 0�̸� �̵� ��ġ �缳��
            else{ // 0 �ƴ� ���
                if(row > 0 && gameboard[n][row-1][col] == 0){ // ���� ���� 0�� ���
                    if(move_position[col] > 0 && gameboard[n][move_position[col]-1][col] == gameboard[n][row][col]){ // �ֱ� ���ڿ� ������ Ȯ��
                        if(check[col] == 0){
                            gameboard[n][move_position[col]-1][col] *= 2; // ���ϱ�
                            gameboard[n][row][col] = 0;
                            check[col] = 1;
                        }
                        else{
                            gameboard[n][move_position[col]][col] = gameboard[n][row][col];
                            gameboard[n][row][col] = 0;
                            move_position[col]++;
                            check[col] = 0;                         
                        }
                    }
                    else{ // �̵�
                        gameboard[n][move_position[col]][col] = gameboard[n][row][col];
                        gameboard[n][row][col] = 0;
                        move_position[col]++;
                        check[col] = 0;
                    }
                }
                else if(row > 0 && gameboard[n][row-1][col] != 0){ // ���� ���� 0�� �ƴ� ���
                    if(row > 0 && gameboard[n][row-1][col] == gameboard[n][row][col]){ // ���� ��� ���ڰ� ������ Ȯ��
                        if(check[col] == 0){
                            gameboard[n][row-1][col] *= 2;
                            gameboard[n][row][col] = 0;
                            move_position[col] = row;  
                            check[col] = 1;
                        }
                    }
                }
            }
        }
    }
}

void MoveDown(int n){
    int check[20];
    memset(check, 0, sizeof(check)); // ���� ���� Ȯ��

    MovePositionArrResetMIN();
    for(int row=boardsize-1; row>=0; row--){
        for(int col=0; col<boardsize; col++){
            if(gameboard[n][row][col]==0){ if(move_position[col] < row){ move_position[col] = row;}} // 0�̸� �̵� ��ġ �缳��
            else{ // 0 �ƴ� ���
                if(row < boardsize-1 && gameboard[n][row+1][col] == 0){ // ���� �湮 ���� 0�� ���
                    if(move_position[col] < boardsize-1 && gameboard[n][move_position[col]+1][col] == gameboard[n][row][col]){ // �ֱ� ���ڿ� ������ Ȯ��
                        if(check[col] == 0){
                            gameboard[n][move_position[col]+1][col] *= 2; // ���ϱ�
                            gameboard[n][row][col] = 0;
                            check[col] = 1;
                        }
                        else{
                            gameboard[n][move_position[col]][col] = gameboard[n][row][col];
                            gameboard[n][row][col] = 0;
                            move_position[col]--;
                            check[col] = 0;                         
                        }
                    }
                    else{ // �̵�
                        gameboard[n][move_position[col]][col] = gameboard[n][row][col];
                        gameboard[n][row][col] = 0;
                        move_position[col]--;
                        check[col] = 0;
                    }
                }
                else if(row < boardsize-1 && gameboard[n][row+1][col] != 0){ // ���� ���� 0�� �ƴ� ���
                    if(row < boardsize-1 && gameboard[n][row+1][col] == gameboard[n][row][col]){ // ���� ��� ���ڰ� ������ Ȯ��
                        if(check[col] == 0){
                            gameboard[n][row+1][col] *= 2;
                            gameboard[n][row][col] = 0;
                            move_position[col] = row;
                            check[col] = 1;
                        }
                    }
                }
            }
        }
    }
}

void MoveLeft(int n){
    int check[20];
    memset(check, 0, sizeof(check)); // ���� ���� Ȯ��

    MovePositionArrResetMAX();
    for(int row=0; row<boardsize; row++){
        for(int col=0; col<boardsize; col++){
            if(gameboard[n][row][col]==0){ if(move_position[row] > col){ move_position[row] = col;}} // 0�̸� �̵� ��ġ �缳��
            else{ // 0 �ƴ� ���
                if(col > 0 && gameboard[n][row][col-1] == 0){ // ���� ���� 0�� ���
                    if(move_position[row] > 0 && gameboard[n][row][move_position[row]-1] == gameboard[n][row][col]){ // �ֱ� ���ڿ� ������ Ȯ��
                        if(check[row] == 0){
                            gameboard[n][row][move_position[row]-1] *= 2; // ���ϱ�
                            gameboard[n][row][col] = 0;
                            check[row] = 1;
                        }
                        else{
                            gameboard[n][row][move_position[row]] = gameboard[n][row][col];
                            gameboard[n][row][col] = 0;
                            move_position[row]++;
                            check[row] = 0;
                        }
                    }
                    else{ // �̵�
                        gameboard[n][row][move_position[row]] = gameboard[n][row][col];
                        gameboard[n][row][col] = 0;
                        move_position[row]++;
                        check[row] = 0;
                    }
                }
                else if(col > 0 && gameboard[n][row][col-1] != 0){ // ���� ���� 0�� �ƴ� ���
                    if(col > 0 && gameboard[n][row][col-1] == gameboard[n][row][col]){ // ���� ��� ���ڰ� ������ Ȯ��
                        if(check[row] == 0){
                            gameboard[n][row][col-1] *= 2;
                            gameboard[n][row][col] = 0;
                            move_position[row] = col;
                            check[row] = 1;
                        }
                    }
                }
            }
        }
    }
}

void MoveRight(int n){
    int check[20];
    memset(check, 0, sizeof(check)); // ���� ���� Ȯ��

    MovePositionArrResetMIN();
    for(int row=0; row<boardsize; row++){
        for(int col=boardsize-1; col>=0; col--){
            if(gameboard[n][row][col]==0){ if(move_position[row] < col){ move_position[row] = col;}} // 0�̸� �̵� ��ġ �缳��
            else{ // 0 �ƴ� ���
                if(col < boardsize-1 && gameboard[n][row][col+1] == 0){ // ���� �湮 ���� 0�� ���
                    if(move_position[row] < boardsize-1 && gameboard[n][row][move_position[row]+1] == gameboard[n][row][col]){ // �ֱ� ���ڿ� ������ Ȯ��
                        if(check[row] == 0){
                            gameboard[n][row][move_position[row]+1] *= 2; // ���ϱ�
                            gameboard[n][row][col] = 0;
                            check[row] = 1;
                        }
                        else{ // �̵�
                            gameboard[n][row][move_position[row]] = gameboard[n][row][col];
                            gameboard[n][row][col] = 0;
                            move_position[row]--;
                            check[row] = 0;
                        }
                    }
                    else{ // �̵�
                        gameboard[n][row][move_position[row]] = gameboard[n][row][col];
                        gameboard[n][row][col] = 0;
                        move_position[row]--;
                        check[row] = 0;
                    }
                }
                else if(col < boardsize-1 && gameboard[n][row][col+1] != 0){ // ���� ���� 0�� �ƴ� ���
                    if(col < boardsize-1 && gameboard[n][row][col+1] == gameboard[n][row][col]){ // ���� ��� ���ڰ� ������ Ȯ��
                        if(check[row] == 0){
                            gameboard[n][row][col+1] *= 2;
                            gameboard[n][row][col] = 0;
                            move_position[row] = col;
                            check[row] = 1;
                        }
                    }
                }
            }
        }
    }
}

void MoveGameBoard(int n, int i){
    if(i==0) MoveUp(n);
    else if(i==1) MoveDown(n);
    else if(i==2) MoveRight(n);
    else if(i==3) MoveLeft(n);
}

void CopyGameBoard(int n){
    if(n==0) copy(&gameboard[0][0][0], &gameboard[0][boardsize][boardsize], &gameboard[1][0][0]);
    else if(n==1) copy(&gameboard[1][0][0], &gameboard[1][boardsize][boardsize], &gameboard[2][0][0]);
    else if(n==2) copy(&gameboard[2][0][0], &gameboard[2][boardsize][boardsize], &gameboard[3][0][0]);
    else if(n==3) copy(&gameboard[3][0][0], &gameboard[3][boardsize][boardsize], &gameboard[4][0][0]);
    else if(n==4) copy(&gameboard[4][0][0], &gameboard[4][boardsize][boardsize], &gameboard[5][0][0]);
}

void CheckGameBoardMaxNumber(){
    for(int i=0; i<boardsize; i++){
        for(int j=0; j<boardsize; j++){
            max_num = max(max_num, gameboard[5][i][j]);
        }
    }
}

void RepeatMoveGameBoard(int n){ // Backtracking
    if(n==5){ // base condition
        CheckGameBoardMaxNumber();
        return;
    }

    for(int i=0; i<4; i++){
        CopyGameBoard(n); // ���ܰ� �̵����� ����
        MoveGameBoard(n+1, i); // �� �̵�
        RepeatMoveGameBoard(n+1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    InputUesrData();
    RepeatMoveGameBoard(0);
    cout <<  max_num << "\n";
}


// Ʋ�� ���� : ��Ÿ�ӿ���(OutofBounds) -> �迭 ũ�� �ø�(20-> 25)
// Ʋ�� ���� : �ߺ� ����(�ѹ� ����� ���ڴ� �� ������� �ʾƾ� ��.) -> check ���



// void OutputUesrData(int n){
//     for(int i=0; i<boardsize; i++){
//         cout << "\n";
//         for(int j=0; j<boardsize; j++){
//             cout << gameboard[n][i][j] << " ";
//         } 
//     }
// }  

// MoveRight(0);
// OutputUesrData(0);