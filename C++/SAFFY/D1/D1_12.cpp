// 2029

#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

	int test_case;
	int T;

    cin >> T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int a,b;
        cin >> a >> b;

        cout << "#" << test_case << " " << a/b << " " << a%b << "\n";
    }

    return 0;
}