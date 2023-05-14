// 1230

#include<bits/stdc++.h>

using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 10;

    for(int test_case = 1; test_case <= T; test_case++){

        list<int> data_list;

        int cnt;
        cin >> cnt;

        int n;
        for(int i=0; i < cnt; i++){
            cin >> n;
            data_list.push_back(n);
        }

        cin >> cnt;
        for(int i = 0 ; i < cnt; i++){

            auto data_list_pos = data_list.begin();

            char c;
            cin >> c;

            if(c == 'I'){
                int x, y;
                cin >> x >> y;

                for(int j = 0; j < x; j++){
                    data_list_pos++;
                }

                list<int> tmp;
                for(int j = 0; j < y; j++){
                    cin >> n;
                    tmp.push_back(n);
                }

                data_list.splice(data_list_pos, tmp);
            }
            else if(c == 'D'){
                int x, y;
                cin >> x >> y;

                for(int j = 0; j < x; j++){
                    data_list_pos++;
                }

                for(int j = 0; j < y; j++){
                    data_list_pos = data_list.erase(data_list_pos);
                }
            }
            else if(c == 'A'){
                int x;
                cin >> x;

                for(int j = 0; j < x; j++){
                    cin >> n;
                    data_list.push_back(n);
                }
            }
            
        }

        auto data_list_pos = data_list.begin();

        cout << "#" << test_case << " ";
        for(int i = 0; i < 10; i++){
            cout << *data_list_pos << " ";
            data_list_pos++;
        }
        cout << "\n";
    
    }
    return 0;
}
