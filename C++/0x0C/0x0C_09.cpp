// https://www.acmicpc.net/problem/15664
// 15664��. N �� M (10)

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
        if(isused[i] > 0){ // ��� Ƚ�� Ȯ��
            if(n > 0 && result_arr[n-1] > i) continue; // ������ ���� ���ں��� Ŭ ��츸 ���
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
        if(isused[tmp] == 0) user_arr.push_back(tmp); // �迭�� ���ڴ� �ϳ��� ���� 
        isused[tmp]++; // �� ���ڰ� ��� �����ߴ��� ����
    }
    sort(user_arr.begin(), user_arr.end()); // ����

    func(0);
}