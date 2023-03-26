// https://www.acmicpc.net/problem/1021
// 1021��. AC

#include<bits/stdc++.h>

using namespace std;

vector<int> split(const string &str, char sep)
{
    vector<int> tokens;
    int i;
    stringstream ss(str);
    while (ss >> i) {
        tokens.push_back(i);
        if (ss.peek() == sep) {
            ss.ignore();
        }
    }
    return tokens;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int user_cnt;
    cin >> user_cnt;

    while(user_cnt--)
    {
        bool front_back = false;
        int num, len, result = 0;
        char action;
        string user_str, user_arr;
        deque<char> DQ_str;
        deque<int> DQ_arr;

        cin >> user_str >> len >> user_arr;

        vector<int> arr = split(user_arr.substr(1, user_arr.length()-2), ','); 

        for(int i=0; i < len; i++) // �迭�� ť�� ���
        {
            DQ_arr.push_back(arr[i]);
        }


        for(auto s: user_str)
        {
            if(!DQ_arr.empty())
            {
                if(s == 'R')
                {   
                    if(front_back == 0) front_back = 1;
                    else if(front_back == 1) front_back = 0;
                }
                else if(s == 'D')
                {
                    if(front_back == false) DQ_arr.pop_front();
                    else if(front_back == true) DQ_arr.pop_back();
                }
            }
            else
            {
                if(s=='D')
                {      
                    result = 1; 
                    break;       
                }
            }
        }


        // ���
        if(result == 1)
        {
            cout << "error" << "\n";
            continue;
        }

        cout << "[";
        if(front_back == false) 
        {
            while(!DQ_arr.empty())
            {
                cout << DQ_arr.front();
                DQ_arr.pop_front();
                if(!DQ_arr.empty()) cout << ",";
             }
        }
        else
        {
            while(!DQ_arr.empty())
            {
                cout << DQ_arr.back();
                DQ_arr.pop_back();
                if(!DQ_arr.empty()) cout << ",";
            }
        }
        cout << "]\n";
    }
}

// split �Լ� �м��غ���

// Ʋ�� ���� : �ð� �ʰ� (swap ���)
// Ʋ�� ���� : continue ����ؾ��ϴµ� break �����.
// Ʋ�� ���� : = �� ����ؾ� �ϴµ� == �� ��.
// Ʋ�� ���� : �׽�Ʈ ���̽�(����ִµ� D �Լ� �� �� ���) 



// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     int user_cnt;
//     cin >> user_cnt;

//     while(user_cnt--)
//     {
//         bool front_back = false;
//         int num, len, result = 0;
//         char action;
//         string user_str, user_arr;
//         deque<char> DQ_str;
//         deque<int> DQ_arr;

//         cin >> user_str >> len >> user_arr;
        
//         for(auto s : user_str) // �Լ� ���� ����ȭ
//         {
//             if(s == 'D')
//             {
//                 DQ_str.push_back('D');
//             }
//             else if(s == 'R')
//             {
//                 if(!DQ_str.empty() && DQ_str.back() == 'R')
//                 {
//                     DQ_str.pop_back();
//                 }
//                 else DQ_str.push_back('R');
//             }
//         }

//         vector<int> arr = split(user_arr.substr(1, user_arr.length()-2), ','); 

//         for(int i=0; i < len; i++) // �迭�� ť�� ���
//         {
//             DQ_arr.push_back(arr[i]);
//         }


//         while(!DQ_str.empty())
//         {
//             action = DQ_str.front();
//             DQ_str.pop_front();

//             if(!DQ_arr.empty())
//             {
//                 if(action == 'R')
//                 {
//                     if(front_back == false) front_back = true;
//                     else if(front_back == true) front_back = false;
//                 }
//                 else if(action == 'D')
//                 {
//                     if(front_back == false) DQ_arr.pop_front();
//                     else if(front_back == true) DQ_arr.pop_back();
//                 }
//             }
//             else
//             {
//                 result = 1;
//                 break;
//             }
//         }


//         // ���
//         if(result == 1)
//         {
//             cout << "error" << "\n";
//             continue;
//         }

//         cout << "[";
//         if(front_back == false) 
//         {
//             while(!DQ_arr.empty())
//             {
//                 cout << DQ_arr.front();
//                 DQ_arr.pop_front();
//                 if(!DQ_arr.empty()) cout << ",";
//              }
//         }
//         else
//         {
//             while(!DQ_arr.empty())
//             {
//                 cout << DQ_arr.back();
//                 DQ_arr.pop_back();
//                 if(!DQ_arr.empty()) cout << ",";
//             }
//         }
//         cout << "]\n";
//     }
// }


