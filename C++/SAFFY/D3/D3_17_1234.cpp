// 1234

#include<bits/stdc++.h>

using namespace std;

char str[105];
int len;

void InputData(){
    cin >> len;
    cin >> str;
}

void CheckData(){
    for(int i=0; i < len-1; i++){
        int k = 0;
        while(str[i-k] == str[i+1+k]){
            str[i-k] = '#';
            str[i+1+k] = '#';

            k++;

            if(i-k < 0 || i+1+k >= len) break;
        }
    }
}

void OutputData(int test_case){
    cout << "#" << test_case << " ";
    for(int i=0; i < len; i++){
        if(str[i] != '#'){
            cout << str[i];
        }
    }
    cout << "\n";
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;

    for(int test_case = 1; test_case <= T; test_case++){
        
        InputData();
        CheckData();
        OutputData(test_case);

    }
    return 0;
}
