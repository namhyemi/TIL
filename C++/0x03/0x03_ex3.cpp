
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

// sort �� �����ߴµ� sort ��ü�� O(n) ���� �����ϰ�, �ذ��� �ȵǼ� �Ⱒ.