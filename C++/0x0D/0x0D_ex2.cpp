// https://www.acmicpc.net/problem/18808
// 18808번. 스티커 붙이기

#include<bits/stdc++.h>

using namespace std;

int laptopX, laptopY;
int stickerX, stickerY;
int sticker[10][10];
int laptop[40][40];

void ResetStickerArr(){
    fill(&sticker[0][0], &sticker[10][10], 0); // memset(sticker, 0, sizeof(sticker));
}

void InputStickerData(){
    ResetStickerArr(); 
    cin >> stickerX >> stickerY;
    for(int i=0; i < stickerX; i++)
        for(int j=0; j < stickerY; j++)
            cin >> sticker[i][j];
}

void OuputStickerData(){
    cout << "\n";
    for(int i=0; i < stickerX; i++){
        for(int j=0; j < stickerY; j++){
            cout << sticker[i][j] << " ";
        } cout << "\n";
    } 
}

int InputLaptopData(){
    int sticker_cnt;
    cin >> laptopX >> laptopY >> sticker_cnt;
    return sticker_cnt;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int sticker_cnt = InputLaptopData();
    
    while(sticker_cnt--){
        InputStickerData();
    }

    
}
