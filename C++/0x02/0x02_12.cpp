// 2309��. �ϰ�������

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a[9], sum=0, cnt=0;

    for(int i=0; i < 9; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    sum = sum - 100;

    for(int i=0; i<8; i++)
    {
        for(int j=i+1; j<9; j++)
        {
            if(a[i]+a[j] == sum)
            {
                a[i] = 0;
                a[j] = 0;
                cnt++;
            }
        }
        if(cnt == 1) break;
    }
    sort(a, a+9);

    for(int i=2; i<9; i++)
    {
        cout << a[i] << '\n';
    }
}

// Ʋ�� ���� : �������� ���� ���� (break�� ��ü�� ����Ǵ��� ��. for �� ����� ������� �ʾƼ� ���� ���������� ��쿡 ������)