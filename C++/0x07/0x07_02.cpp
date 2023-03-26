// https://www.acmicpc.net/problem/1021
// 1021번. 회전하는 큐

#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<int> DQ;
    int num , cnt, addr, tmp;
    int result=0;


    cin >> num >> cnt;

    for(int i=1; i <= num ; i++){
        DQ.push_back(i);
    }

    while(cnt--)
    {
        cin >> num;
        for(int i=0; i < DQ.size(); i++) // 찾아야 하는 숫자 위치 찾기
        {
            if(DQ[i]==num)
            {
                addr = i;
                break;
            }
        }  // int addr = find(DQ.begin(), DQ.end(), num) - DQ.begin(); // idx : t가 있는 위치
        while(DQ.front() != num) // 찾아야 하는 숫자가 맨 앞으로 올 때까지 반복
        {
            if(addr <= DQ.size()/2) // 찾아야 하는 숫자가 앞쪽에 있는 경우
            {
                tmp = DQ.front();
                DQ.pop_front(); 
                DQ.push_back(tmp); // DQ.push_back(DQ.front()); DQ.pop_front();

            }
            else // 찾아야 하는 숫자가 뒷쪽에 있는 경우
            {
                tmp = DQ.back();
                DQ.pop_back();
                DQ.push_front(tmp);
            }
            result++;
        }
        DQ.pop_front();
    }
    cout << result << "\n";
}


