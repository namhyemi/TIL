// https://www.acmicpc.net/problem/11003
// 11003번. 최솟값 찾기

// 다시 풀기

#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    deque<pair<int, int>> dq;

    cin >> n >> m;

    for(int i=0; i < n; i++)
    {
        int num;
        cin >> num;

        while(!dq.empty() && dq.back().second >= num) dq.pop_back();

        dq.push_back({i,num});

        if(dq.front().first <= i - m) dq.pop_front();

        cout << dq.front().second << " ";
    }
}


// 틀린 이유 : 시간 초과 (이중포문사용)

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     deque<int> DQ;
//     int num, cnt, tmp;

//     cin >> num >> cnt;
//     for(int i=0; i < num; i++)
//     {
//         cin >>  tmp;
//         DQ.push_back(tmp);
//     }

//     while(cnt-- > 1)
//     {
//         for(int i=0; i < num; i++)
//         {
//             if(i == 0)
//             {
//                 tmp = DQ.front();
//                 DQ.push_back(tmp);
//             }
//             else
//             {
//                 tmp = DQ.front();
//                 DQ.pop_front();
//                 DQ.push_back(min(tmp, DQ.front()));
//             }
//         }
//         DQ.pop_front();
//     }

//     while(!DQ.empty())
//     {
//         cout << DQ.front() << " ";
//         DQ.pop_front();
//     }
// }
