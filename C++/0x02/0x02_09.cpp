// 2490번. 윷놀이

#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a[4];
    int b=0;
    
    for(int i=0; i<3; i++)
    {   
        cin >> a[0] >> a[1] >> a[2] >> a[3];
        sort(a, a+4);
        
        if(a[0] == 1) cout << 'E';
        else if(a[0] != a[1]) cout << 'A';
        else if(a[1] != a[2]) cout << 'B';
        else if(a[2] != a[3]) cout << 'C';
        else cout << 'D';

        cout << '\n';
    }
}

// 틀린 이유 : 3번 반복인데 한번만 출력함.
// 의문점 : 입력값을 다 받은 후에 출력을 몰아서 함.(=> 인터프리터 언어가 아니기 때문에?)


    // int result, input;
    // string res = "DCBAE";   

    // for(int r = 0; r < 3; r++) {
    //     result = 0;
    //     for(int c = 0; c < 4; c++) {
    //     cin >> input;
    //     result += input;
    //     }
    //     cout << res[result] << '\n';
    // }
