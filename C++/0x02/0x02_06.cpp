// 2752번. 세수정렬

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b,c;

    cin >> a >> b >> c;
    if(a < b)
        if(b < c) cout << a << ' ' << b << ' ' << c;
        else if(a < c) cout << a << ' ' << c << ' ' << b;
        else cout << c << ' ' << a << ' ' << b;
    else 
        if(a < c) cout << b << ' ' << a << ' ' << c;
        else if(b < c) cout << b << ' ' << c << ' ' << a;
        else cout << c << ' ' << b << ' ' << a;
    cout << '\n';
}


// int main(void){
//   ios::sync_with_stdio(0);
//   cin.tie(0);

//   int arr[4];
//   for(int i=0;i<3;i++){
//     cin>>arr[i];
//   }
//   sort(arr, arr+3);
//   for(int i=0;i<3;i++){
//     cout<<arr[i]<<" ";
//   }
// }