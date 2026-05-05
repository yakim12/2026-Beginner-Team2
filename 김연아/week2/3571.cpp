#include <iostream>
#include <stack>
#include <string>  
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;

    getline(cin, str);
    while (str.substr(0, 1).compare("0")) { //같으면 0 반환 

        stack<char> st; //매 줄마다 새 스택에 저장(스택 초기화)
        bool valid = true; //유효 검사 플래그 

        for (int i = 0; i < str.size(); i++) {
            if (str.at(i) == '(') st.push('(');
            else if (str.at(i) == ')') {
                if (st.empty()) {
                    valid = false;
                    break; //for loop 탈출 
                }
                st.pop();
            }
        }

        if (st.empty() && valid) cout << "YES" << endl;
        else cout << "NO" << endl;

        getline(cin, str);
    }

}