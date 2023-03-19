// 1267번. 핸드폰 요금

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    int Y, M, sumY=0, sumM=0;

    cin >> a;
    for(int i=0; i<a; i++)
    {
        cin >> b;

        Y = (b / 30 + 1) * 10;
        sumY += Y;
        M = (b / 60 + 1) * 15;
        sumM += M;
    }

    if(sumY > sumM) cout << "M " << sumM;
    else if(sumY < sumM) cout << "Y " << sumY;
    else cout << "Y M " << sumY;
    cout << "\n";
}