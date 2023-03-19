//10871번. X보다 작은 수
#include<stdio.h>

int main()
{
    int N,X;
    int A[10000];

    scanf("%d %d", &N, &X);
    for(int i=0; i<N; i++)
    {
        scanf("%d", &A[i]);
    }
    for(int i=0; i<N; i++)
    {
        if(A[i] < X)
        {
            printf("%d ", A[i]);
        }
    }
    printf("\n");
    return 0;
}


// C++ (코테.ver)
// #include <iostream>

// using namespace std;

// int n,x,a;

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cin >> n >> x;
//     for(int i=0; i < n; i++)
//     {
//         cin >> a;
//         if(a < x) cout << a << ' '; 
//     }
//     cout << '\n';
// }

// C++ (개발.ver)
// #include <iostream>
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     int n,x;
//     int* a = new int[n];
// 
//     std::cin >> n >> x;
//     for(int i=0; i < n; i++)
//     {
//         std::cin >> a[i];
//     }
//     for(int i=0; i < n; i++)
//     {
//         if(a[i] < x) std::cout << a[i] << ' ';
//     }
//     delete[] a;
// }
