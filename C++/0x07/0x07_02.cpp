// https://www.acmicpc.net/problem/1021
// 1021��. ȸ���ϴ� ť

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
        for(int i=0; i < DQ.size(); i++) // ã�ƾ� �ϴ� ���� ��ġ ã��
        {
            if(DQ[i]==num)
            {
                addr = i;
                break;
            }
        }  // int addr = find(DQ.begin(), DQ.end(), num) - DQ.begin(); // idx : t�� �ִ� ��ġ
        while(DQ.front() != num) // ã�ƾ� �ϴ� ���ڰ� �� ������ �� ������ �ݺ�
        {
            if(addr <= DQ.size()/2) // ã�ƾ� �ϴ� ���ڰ� ���ʿ� �ִ� ���
            {
                tmp = DQ.front();
                DQ.pop_front(); 
                DQ.push_back(tmp); // DQ.push_back(DQ.front()); DQ.pop_front();

            }
            else // ã�ƾ� �ϴ� ���ڰ� ���ʿ� �ִ� ���
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


