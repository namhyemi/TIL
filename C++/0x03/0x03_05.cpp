// https://www.acmicpc.net/problem/13300
// 13300번. 반 배정

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num, k, a, b, result=0;
    int w[6] = {}, m[6] = {};

    cin >> num >> k;

    for(int i=0; i < num; i++)
    {
        cin >> a >> b;
        if(a == 0) w[b-1]++;
        else m[b-1]++;
    }

    for(int i=0; i < 6; i++)
    {
        if(w[i] % k == 0) result += w[i] / k;
        else result += (w[i] / k + 1);

        if(m[i] % k == 0) result += m[i] / k;
        else result += (m[i] / k + 1);        
    }

    cout << result << "\n";
}