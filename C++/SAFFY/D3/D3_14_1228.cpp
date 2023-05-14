// 1228

#include<bits/stdc++.h>

using namespace std;

deque<int> data_arr;
deque<int> result_arr;

void InputData(){
    int num;
    cin >> num;

    for(int i=0; i<num; i++){
        int n;
        cin >> n;
        result_arr.push_back(n);
    }
}

void MoveData(){
    while(!result_arr.empty()){
        data_arr.push_back(result_arr.front());
        result_arr.pop_front();
    }
}

void AppendData(){
    int num;
    cin >> num;

    for(int i=0; i < num; i++){
        char c;
        int pos, cnt;
        cin >> c >> pos >> cnt;

        MoveData();

        if(pos > 10) pos = 10;
        for(int j=0; j < pos; j++){
            if(result_arr.size() < 10){
                result_arr.push_back(data_arr.front());
            }
            data_arr.pop_front();
        }

        for(int j=0; j < cnt; j++){
            int number;
            cin >> number;

            if(result_arr.size() < 10){
                result_arr.push_back(number);
            }  
        }

        int last = data_arr.size();
        for(int j=0; j < last; j++){
            if(result_arr.size() < 10){
                result_arr.push_back(data_arr.front());
            }
            data_arr.pop_front();
        }
    }

}

void OutPutData(int test_case){
    cout << "#" << test_case << " ";

    while(!result_arr.empty()){
        cout << result_arr.front() << " ";
        result_arr.pop_front();
    }
    cout << "\n";
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 10;

    for(int test_case = 1; test_case <= T; test_case++){

        InputData();
        AppendData();
        OutPutData(test_case);
    }

    return 0;
}
