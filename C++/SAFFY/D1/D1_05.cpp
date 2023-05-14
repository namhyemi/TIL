// 2063

#include<bits/stdc++.h>
 
using namespace std;
 
vector<int> arr;
 
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int test_case;
    int T;
 
    cin>>T;
 
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int num;
        cin >> num;
 
        arr.push_back(num);
    }
    sort(arr.begin(),arr.end());
 
    cout << arr[T/2] << "\n";
 
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}