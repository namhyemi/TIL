// 1225

#include<bits/stdc++.h>

using namespace std;

deque<int> number_arr;
int arr[5] = {1,2,3,4,5};

void InputData(){
    int num;
    cin >> num;

    for(int i = 0; i < 8; i++){
        cin >> num;
        number_arr.push_back(num);
    }
}

void Check(){
    int i = 0;
    while(1){
        int num = number_arr.front();
        number_arr.pop_front();

        num -= arr[i % 5];
        i++;

        if(num <= 0){
            number_arr.push_back(0);
            break;
        }
        else number_arr.push_back(num);
    }
}

void OutputData(int test_case){

    cout << "#" << test_case << " ";

    while(!number_arr.empty()){
        cout << number_arr.front() << " ";
        number_arr.pop_front();
    }
    cout << "\n";
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 10;

    for(int test_case = 1; test_case <= T; test_case++){
        
        InputData();
        Check();
        OutputData(test_case);
    }
    return 0;
}
