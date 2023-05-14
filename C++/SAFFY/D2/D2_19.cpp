// 1948

#include<bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    
    for(int test_case = 1; test_case <= T; test_case++){
        int cnt;
        cin >> cnt;
        
        cout << "#" << test_case << "\n";
        int check = 0;
        for(int i = 0; i < cnt; i++){
            char ch;
            int n;
            cin >> ch >> n;
            
            for(int j=0; j < n; j++){
                cout << ch;
                check++;
                if(check == 10){
                    cout << "\n";
                    check = 0;
                }
            }
        }
        cout << "\n";
    }
    return 0;
}


/*

int alp_arr[30];

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    
    for(int test_case = 1; test_case <= T; test_case++){
        int cnt;
        cin >> cnt;

        int sum = 0;
        for(int i=1; i<=cnt; i++){
            char alp;
            int num;
            cin >> alp >> num;

            alp_arr[alp-'A'] = num;
            sum += num;
        }

        cout << "#" << test_case << " " << "\n";
        int j = 1;
        for(int i=0; i < 30; i++){
            while(alp_arr[i]){
                alp_arr[i]--;
                char ch = i + 'A';
                cout << ch;
                if(j % 10 == 0) cout << "\n";
                j++;
            }
        }
        cout << "\n";
    }
    return 0;
}

*/