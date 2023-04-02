// https://www.acmicpc.net/problem/5014
// 5014번. 스타트링크

#include<bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int vit[1000000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;

    queue<int> Q;
    int result = 0;

    Q.push(S);
    vit[S] = 1;

    while(!Q.empty()){
        int pos = Q.front(); Q.pop();
        if(pos == G){
            cout << vit[pos]-1 << "\n";
            result = 1;
            break;
        }
        for(int move : {pos + U, pos - D}){
            if(move < 1 || move > F) continue;
            if(vit[move] > 0) continue;

            vit[move] = vit[pos]+1;
            Q.push({move});
        }
    }
    if(!result) cout << "use the stairs\n";
}
