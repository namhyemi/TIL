// https://www.acmicpc.net/problem/15664
// 15664번. N 과 M (10)

#include<bits/stdc++.h>

using namespace std;

int N, M;
int result_arr[10];
int isused[10005];
vector<int> user_arr;

void func(int n){
    if(n==M){
        for(int i=0; i<M; i++) cout << result_arr[i] << " ";
        cout << "\n";
        return;
    }

    for(auto i : user_arr){
        if(isused[i] > 0){ // 사용 횟수 확인
            if(n > 0 && result_arr[n-1] > i) continue; // 수열의 이전 숫자보다 클 경우만 사용
            isused[i]--;
            result_arr[n] = i;
            func(n+1);
            isused[i]++;
        }
    }
}

int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    int tmp;
    for(int i=0; i<N; i++){ 
        cin >> tmp;
        if(isused[tmp] == 0) user_arr.push_back(tmp); // 배열에 숫자는 하나만 저장 
        isused[tmp]++; // 각 숫자가 몇번 등장했는지 저장
    }
    sort(user_arr.begin(), user_arr.end()); // 정렬

    func(0);
}