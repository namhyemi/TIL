// 10804번. 카드 역배치

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, x, tmp;
    int card[20];

    for(int i=0; i<20; i++)
    {
        card[i] = i+1;
    }

    for(int i=0 ; i< 10; i++)
    {
        cin >> a >> b;
        x = b-a+1;

        if(x == 1) continue;
        else
        {
            for(int i=0; i< x/2 ; i++)
            {
                swap(card[a+i-1], card[b-i-1]);
            }
        }
    }
    
    for(int i=0; i<20; i++)
    {
        cout << card[i] << " ";
    }

    cout << "\n";
}
