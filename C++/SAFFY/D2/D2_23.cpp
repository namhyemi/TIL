// 1288

#include<bits/stdc++.h>

using namespace std;

int num[10];

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    
    for(int test_case = 1; test_case <= T; test_case++){
        int n;
        cin >> n;

        int cur_n = 0;
        int cnt = 0;
        memset(num, 0, sizeof(num));
        while(cnt != 10){
            cur_n += n;

            int tmp = cur_n;
            while(tmp){
                if(num[tmp % 10] == 0){
                    cnt++;
                    num[tmp % 10]++;
                }
                tmp /= 10;
            }
        }

        cout << "#" << test_case << " " << cur_n << "\n";
    }
    return 0;
}


/*
int num[10];

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    
    for(int test_case = 1; test_case <= T; test_case++){
        int n;
        cin >> n;

        int cur_n = 0;
        memset(num, 0, sizeof(num));
        while(1){
            cur_n += n;
            
            int tmp = cur_n;
            while(tmp){
                num[tmp % 10]++;
                tmp /= 10;
            }

            bool flag = 1;
            for(int i=0; i<10; i++){
                if(num[i] == 0){
                    flag = 0;
                }
            }
            if(flag == 1) break;
        }

        cout << "#" << test_case << " " << cur_n << "\n";
    }
    return 0;
}
*/