// 2439번. 별찍기-2

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a;

    cin >> a;

    int* arr = new int[a];
    
    for(int i=0; i < a; i++)
    {
        for(int i=0; i < a ;i++)
        {
            arr[i] = 0;
        }        
        for(int j=a-i; j > 1; j--)
        {
            arr[a-(j+i)] = 1;
        }
        for(int j=0; j < a; j++)
        {
            if(arr[j] == 0) cout << '*';
            else cout << ' ';
        }
        cout << "\n";
    }
}

// 왜이렇게 복잡하게 생각했는지?