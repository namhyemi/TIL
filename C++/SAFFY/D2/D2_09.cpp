// 1983

#include<bits/stdc++.h>

using namespace std;

string degree[10] = {"A+","A0","A-","B+","B0","B-","C+","C0","C-","D0"};
int sum_arr[105];

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    
    for(int test_case = 1; test_case <= T; test_case++){
        int N, K;
        cin >> N >> K;

        memset(sum_arr, 0, sizeof(sum_arr));

        for(int i=1; i <= N; i++){
            int a, b, c;
            cin >> a >> b >> c;

            sum_arr[i] = a * 35 + b * 45 + c * 20;
        }

        int range = 0;
        for(int i=1; i <= N; i++){
            if(sum_arr[K] < sum_arr[i]) range++;
        }
        
        int div = N/10;
        cout << "#" << test_case << " " << degree[range/div] << "\n";
    }   
    return 0;
}

/*
#include<bits/stdc++.h>

using namespace std;

float sum_arr[105];

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    
    for(int test_case = 1; test_case <= T; test_case++){
        int N, K;
        cin >> N >> K;

        memset(sum_arr, 0, sizeof(sum_arr));

        for(int i=1; i <= N; i++){
            int a, b, c;
            cin >> a >> b >> c;

            sum_arr[i] = a * 0.35 + b * 0.45 + c * 0.2;
        }

        int range = 0;
        for(int i=1; i <= N; i++){
            if(sum_arr[K] < sum_arr[i]) range++;
        }
        
        int div = N / 10;
        string str;
        if(range < div*1) str = "A+";
        else if(range < div*2) str = "A0";
        else if(range < div*3) str = "A-";
        else if(range < div*4) str = "B+";
        else if(range < div*5) str = "B0";
        else if(range < div*6) str = "B-";
        else if(range < div*7) str = "C+";
        else if(range < div*8) str = "C0";
        else if(range < div*9) str = "C-";
        else if(range < div*10) str = "D0";

        cout << "#" << test_case << " " << str << "\n";
    }   
    return 0;
}
*/