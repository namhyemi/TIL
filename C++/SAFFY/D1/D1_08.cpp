// 2050

#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    for(char s : str){
        cout << s - 'A' + 1 << " ";
    }

	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}