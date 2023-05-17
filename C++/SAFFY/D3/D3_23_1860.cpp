// 1860

// Á¶°Ç(0ÃÊ µµÂø)

#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>

using namespace std;

int guest[15000];

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for(int test_case = 1; test_case <= T; test_case++){

		int N, M, K;
		cin >> N >> M >> K;

		memset(guest, 0, sizeof(guest));

		int tmp;
		for(int i = 0; i < N; i++){
			cin >> tmp;
			guest[tmp]++;
		}

		int inven = 0;
		string ans = "Possible";
		for(int i = 0; i <= 15000; i++){
			if(i != 0 && i % M == 0){
				inven += K;
			}
			inven -= guest[i];
			if(inven < 0){
				ans = "Impossible";
				break;
			}
		}
		
		cout << "#" << test_case << " " << ans << "\n";
	}
	return 0;
}

/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int t;
    cin >> t;
    
    for(int i = 1; i <= t; i++)
    {
        int N, M, K;
        vector<int> guest;
        bool ans = true;
        
        cin >> N >> M >> K;
        
        for(int j = 0; j < N; j++)
        {
            int tmp;
            cin >> tmp;
        	guest.push_back(tmp);
        }
        
       	sort(guest.begin(), guest.end());
        
        for(int j = 0; j < N; j++)
        {
            if(K * (guest[j] / M) < j + 1)
            {
                ans = false;
                break;
            }
        }
        
        if(ans)
            cout << "#" << i << " Possible" << endl;
        else
            cout << "#" << i << " Impossible" << endl;
    }
    return 0;
}
*/