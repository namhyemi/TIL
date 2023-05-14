// 1936

#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int A, B;
    cin >> A >> B;

    if(A == 1){
        if(B == 2) cout << "B";
        else cout << "A";
    }
    else if(A == 2){
        if(B == 1) cout << "A";
        else cout << "B";
    }
    else{
        if(B == 1) cout << "B";
        else cout << "A";
    }

    return 0;
}
