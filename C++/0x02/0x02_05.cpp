// 9498번. 시험 성적

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a;

    cin >> a;    
    if(a >= 90) cout << "A\n";
    else if(a >= 80) cout << "B\n";
    else if(a >= 70) cout << "C\n";
    else if(a >= 60) cout << "D\n";
    else cout << "F\n";
}

// else if 는 C, elif 는 python 
// C 에서는 '' 와 "" 는 다름