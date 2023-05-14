// 2068

#include<bits/stdc++.h>
 
using namespace std;
 
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int test_case;
    int T;
 
    cin>>T;
 
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int max_num = 0;
        for(int i=0; i < 10; i++){
            int num;
            cin >> num;
 
            max_num = max(max_num, num);
        }
        cout << "#" << test_case << " " << max_num << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}