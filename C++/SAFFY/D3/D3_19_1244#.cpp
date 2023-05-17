// 1244

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ans, change;
string s;

void dfs(int index, int current)
{
    if(current == change)
    {
        ans = max(ans, stoi(s));
        return;
    }
    for(int i = index; i < s.size() - 1; i++)
    {
        for(int j = i + 1; j < s.size(); j++)
        {
            swap(s[i], s[j]);
            dfs(i, current + 1);
            swap(s[i], s[j]);
        }
    }
}

int main(void)
{
    int t;
    cin >> t;
    
    for(int i = 1; i <= t; i++)
    {
        cin >> s >> change;
        ans = 0;
        
        if(change > s.size())
            change = s.size();
        
        dfs(0, 0);
        cout << "#" << i << " " << ans << endl;
    }
    return 0;
}


/*
#include <iostream>
#include <string.h>
#include <algorithm>
#include <climits>
#include <cmath>
#include <string>
#include <cassert>
#include <queue>
#include <string>
#include <queue>
#define MOD 1234567891
//#pragma warning(disable:4996)
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pip;//{순서,{y,x}}
typedef pair<pii, pii> pp;//{{-likeCnt,-blankCnt},{y,x}}//크,크,작
#define endl '\n'


int N, M, flag = 0, gap = 0;
string num, maxv, ans;

bool isGap() {
	for (int i = 1; i < N; i++) {
		if (num[i - 1] == num[i]) return true;
	}
	return false;
}

void solve(int m) {
	if (flag) return;
	if (num == maxv) {
		if (m % 2 == 0 || gap) {
			ans = num;
			flag = 1; return;
		}
		assert(N - 2 >= 0);
		swap(num[N - 1], num[N - 2]);
		ans = num;
		flag = 1; return;
	}
	if (m == 0) {
		ans = max(ans, num);
		return;
	}

	for (int i = 0; i < N; i++)for (int j = i + 1; j < N; j++) {
		if (num[i] < num[j]) {
			swap(num[i], num[j]);
			solve(m - 1);
			if (flag) return;
			swap(num[i], num[j]);
		}
	}
}

void printArr() {
	cout << ans;
}

void init() {
	cin >> num >> M; N = num.length();
	maxv = num;
	sort(maxv.begin(), maxv.end(), greater<>());
	gap = isGap(); flag = 0;
}

int main() {
	// freopen("sample_input.txt", "r", stdin);
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t; cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		init();
		solve(M);
		cout << "#" << tc << " ";
		printArr(); cout << endl;
	}


	// fclose(stdin);
}
*/