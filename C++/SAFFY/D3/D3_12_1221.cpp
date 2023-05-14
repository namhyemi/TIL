// 1221

#include<bits/stdc++.h>

using namespace std;

int number_arr[15];
string number_name[10] = {"ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN"};

void ResetData(){
    memset(number_arr, 0, sizeof(number_arr));
}

void InputTable(string str){
    for(int i = 0; i < 10; i++){
        if(!str.compare(number_name[i])){
            number_arr[i]++;
            break;
        }
    }
}


void InputData(){
    string str;
    cin >> str;

    int num;
    cin >> num;

    for(int i = 0; i < num; i++){
        cin >> str;
        InputTable(str);
    }
}

void OutputData(int test_case){
    cout << "#" << test_case << "\n";
    for(int i=0; i < 10; i++){
        for(int j=0; j < number_arr[i]; j++){
            cout << number_name[i] << " ";
        }
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for(int test_case = 1; test_case <= T; test_case++){
        
        ResetData();
        InputData();
        OutputData(test_case);

    }
    return 0;
}
