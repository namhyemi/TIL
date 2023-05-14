// 1959

#include<bits/stdc++.h>

using namespace std;

int A[25];
int B[25];

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    
    for(int test_case = 1; test_case <= T; test_case++){
        int A_len, B_len;
        cin >> A_len >> B_len;

        for(int i=0; i < A_len; i++) cin >> A[i];
        for(int i=0; i < B_len; i++) cin >> B[i];
        
        
        int max_sum = 0;

        if(A_len > B_len){
            for(int i=0; i <= A_len-B_len; i++){
                int sum = 0;
                for(int j=0; j < B_len; j++){
                    sum += (A[i+j] * B[j]);
                }
                max_sum = max(sum, max_sum);
            }          
        }  
        else if(B_len > A_len){
            for(int i=0; i <= B_len-A_len; i++){
                int sum = 0;
                for(int j=0; j < A_len; j++){
                    sum += (B[i+j] * A[j]);
                    
                }
                max_sum = max(sum, max_sum);
            }    
        }
    
        else{
            for(int i=1; i < A_len; i++){
                max_sum += (A[i] * B[i]);
            }
        }

        cout << "#" << test_case << " " << max_sum << "\n";
    }
    return 0;
}
