// https://www.acmicpc.net/problem/11659
// 11659��. ���� �� ���ϱ� 4

#include <bits/stdc++.h>

using namespace std;

int arr[100005]; 
int num, range;

void InputUserData(){
    int n;
    cin >> num >> range;   

    for(int i=1; i<=num; i++){
        cin >> n;
        arr[i] = arr[i-1] + n;
    }
}

void OutputResultData(){
    int start, end;
    while(range--){
        cin >> start >> end;
        cout << arr[end] - arr[start-1] << "\n";
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    InputUserData();
    OutputResultData();
}

// DP (Prefix sum) - ���� Ǫ�� ������ �� ��ҷ� ���