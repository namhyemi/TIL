// https://www.acmicpc.net/problem/16987
// 16987��. ������� ���ġ��

#include<bits/stdc++.h>

#define X first // ������
#define Y second // ����

using namespace std;

int N;
int max_num = 0;
pair<int,int> user_arr[10];

void func(int n){ // �Լ� ���� : �ް� �ڸ�
    if(n == N){ // ������ �ް� �ڸ�
        int cnt=0;
        for(int i=0; i<N; i++){
            // cout << user_arr[i].X << " ";
            if(user_arr[i].X < 1){
                cnt++;
            // } cout << "\n";
            }
        }
        max_num = max(max_num, cnt);
        return ; 
    }

    if(user_arr[n].X < 1){ // ���� �ް�
        func(n+1);
        return;
    }

    for(int i=0; i<N; i++){ // ��� ��� ����
        if(n==i && i==N-1) func(n+1); // ������ �ް����� �ڱ� �ڽŸ� �������
        if(n==i) continue; // �ڱ� �ڽ��� ��� �н�
        if(user_arr[i].X < 1) continue; // ���� �ް� �н�
        
        user_arr[i].X -= user_arr[n].Y; // ������ ����
        user_arr[n].X -= user_arr[i].Y; // ������ ����
        func(n+1);
        user_arr[i].X += user_arr[n].Y; 
        user_arr[n].X += user_arr[i].Y;
    }
}

int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) cin >> user_arr[i].X >> user_arr[i].Y;

    func(0);

    cout << max_num << "\n";
}





// Ʋ�� ���� : ������ �ް��� ���� ��� ���� -> N_copy ����
/*
#include<bits/stdc++.h>

#define X first // ������
#define Y second // ����

using namespace std;

int N, N_copy;
int max_num = 0;
pair<int,int> user_arr[10];

void func(int n){ // �Լ� ���� : �ް� �ڸ�
    if(n==N){ 
        int egg_cnt=0;
        for(int i=0; i< N_copy; i++) // �ް� ������ Ȯ��
            if(user_arr[i].X < 1) egg_cnt++;
        max_num = max(max_num, egg_cnt);
        return;
    }
    for(int i=n; i<N ;i++){
        if(i==N-1) func(i+1); // ������ �ް��� ��� �н�
        if(user_arr[i].X > 0){ // ������ Ȯ��
            for(int j=0; j<N; j++){
                if(i==j) continue; // �ڱ� �ڽ� �н�
                if(user_arr[j].X < 1) continue; // ���� �ް����� Ȯ�� (������ Ȯ��)
                
                if(j==N_copy-1 && user_arr[j].X - user_arr[i].Y < 1) N--; // ���� �ް��� ������ �ް��ε� �������
                user_arr[i].X -= user_arr[j].Y; // ���� �ް� ������ - ���� �ް� ����
                user_arr[j].X -= user_arr[i].Y; // ���� �ް� ������ - ���� �ް� ����
                func(i+1);
                user_arr[i].X += user_arr[j].Y; // ���� �ް� ������ + ���� �ް� ����
                user_arr[j].X += user_arr[i].Y; // ���� �ް� ������ + ���� �ް� ����
                if(j==N-1 && user_arr[j].X - user_arr[i].Y < 1) N++; // ���� �ް��� ������ �ް��ε� �������               
            }
        }
    }
}

int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    N_copy = N;
    for(int i=0; i<N; i++) cin >> user_arr[i].X >> user_arr[i].Y;

    func(0);

    cout << max_num;
}
*/