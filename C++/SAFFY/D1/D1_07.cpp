// 2056

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
        string num;
        cin >> num;

        int year, mon, day;
        year = stoi(num.substr(0,4));
        mon = stoi(num.substr(4,2));
        day = stoi(num.substr(6,2));

        bool check = true;
        if(mon == 1 || mon == 3 || mon == 5 || mon == 7 || mon == 8 || mon == 10 || mon == 12){
            if(day < 32 && day > 0){ check = true; }
            else check = false;
        }
        else if(mon == 2){
            if(day < 29 && day > 0){ check = true; }
            else check = false;
        }
        else if(mon == 4 || mon == 6 || mon == 9 || mon == 11){
            if(day < 31 && day > 0){ check = true; }
            else check = false;
        }
        else check = false;

        if(check == 0) cout << "#" << test_case << " " << "-1\n";
        else cout << "#" << test_case << " " << num.substr(0,4) << "/" << num.substr(4,2) << "/" << num.substr(6,2) << "\n" ;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}