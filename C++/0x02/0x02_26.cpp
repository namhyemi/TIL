// 2447¹ø. ÃÖ´ñ°ª

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, max=0, cnt;

    for(int i=0; i < 9; i++)
    {
        cin >> a;
        if(max < a)
        {
            max = a;
            cnt = i+1;
        }
    }
    cout << max << "\n" << cnt;
    cout << "\n";
}

// max_element() ÇÔ¼ö ¼÷Áö