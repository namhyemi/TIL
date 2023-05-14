// 1545

#include<bits/stdc++.h>
 
using namespace std;
 
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
     
    int num;
    cin >> num;
 
    int result = 1;
     
    cout << result << " ";
    while(num--){
        result = (result << 1);
        cout << result << " ";
    }
 
    return 0;
}
