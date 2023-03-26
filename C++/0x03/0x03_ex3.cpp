
#include <bits/stdc++.h>

using namespace std;

int func2(int arr[], int N)
{
    int occur[101] = {};

    for(int i=0; i < N ;i++)
    {
        if(occur[100-arr[i]] == 1) return 1;
        occur[arr[i]] = 1;
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[3] = {1,52,48};
    cout << func2(arr, 3);
}

// sort 를 생각했는데 sort 자체가 O(n) 보다 복잡하고, 해결이 안되서 기각.