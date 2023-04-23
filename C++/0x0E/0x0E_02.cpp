// https://www.acmicpc.net/problem/2751
// 2751��. �� �����ϱ�2

#include<bits/stdc++.h>

using namespace std;

vector<int> v;

void InputUserDate(){
    int cnt;
    cin >> cnt;
    while(cnt--){
        int num;
        cin >> num;

        v.push_back(num);
    }
}

void OutputData(){
    for(int i=0; i < v.size() ;i++){
        cout << v[i] << "\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    InputUserDate();
    sort(v.begin(), v.end());
    OutputData();
}

/*
STL sort �� quick sort ������ �Ϲ������� �˰��ִ� �������� ������ ���ķ�, �־��� ��쿡�� O(NlogN) ����.
*/