// 2058

#include<bits/stdc++.h>
 
using namespace std;
 
 
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int num;
    cin >> num;
 
    int sum = 0;
    while(num > 0){
        sum += num % 10;
        num /= 10;
    }
 
    cout << sum << "\n";
 
    return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}