// 1229

#include<bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 10;

    for(int test_case = 1; test_case <= T; test_case++){

        list<int> data_list;

        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            int num;
            cin >> num;
            data_list.push_back(num);
        }

        cin >> n;
        for(int i = 0; i < n; i++){

            char c;
            int x, y;
            cin >> c >> x >> y;

            list<int> tmp;
            auto list_pos = data_list.begin();
            if(c == 'I'){
                for(int j = 0; j < x; j++){
                    list_pos++;
                }

                for(int j = 0; j < y; j++){
                    int num;
                    cin >> num;
                    tmp.push_back(num);
                }

                data_list.splice(list_pos, tmp);
            }

            else if(c == 'D'){
                for(int j = 0; j < x; j++){
                    list_pos++;
                }
                
                for(int j = 0; j < y; j++){
                    list_pos = data_list.erase(list_pos);
                }
            }
        }

        auto list_pos = data_list.begin();
        cout << "#" << test_case << " ";
        for(int i = 0; i < 10; i++){
            cout << *list_pos << " ";
            list_pos++;
        }
        cout << "\n";
        
    }

    return 0;
}
