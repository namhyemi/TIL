// 2071

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
        int sum = 0;
        for(int i=1; i <= 10; i++){
            int num; 
            cin >> num;

            sum += num;
        }

        int result = 0;
        if(sum % 10 >= 5){
            result = sum / 10;
            result++;
        }
        else result = sum / 10;
        cout << "#" << test_case << " " << result << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}