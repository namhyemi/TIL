// 1213

#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int T = 10;
 
    for(int test_case = 1; test_case <= T; test_case++){
 
        int cnt;
        cin >> cnt;
 
        string search_st;
        string main_st;
 
        cin >> search_st >> main_st;
 
        int ans = 0;
        for(int i=0; i < main_st.length() - search_st.length() + 1; i++){
            if(main_st[i] == search_st[0]){
                int cur = 1;
                while(main_st[i+cur] == search_st[cur]){
                    cur++;
                    if(cur == search_st.length()){
                        ans++;
                        break;
                    }
                }
            }
        }
 
        cout << "#" << test_case << " " << ans  << "\n";
    }
 
    return 0;
}