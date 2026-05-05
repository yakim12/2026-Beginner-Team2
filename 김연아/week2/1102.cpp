#include <iostream>
#include <stack>
#include <string>  //stoi
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<int> st;

    int n;
    cin >> n; //버퍼에 개행문자 \n 남겨둠 
    cin.ignore(); // 버퍼에 남은 개행 제거

    string str;

    for (int i = 0; i < n; i++) {
        getline(cin, str);
        if (str.at(0) == 'i') st.push(stoi(str.substr(2)));
        //정수형스택이므로 형변환
        //i 123 처럼 여러자리숫자 push 하는 경우 고려 

        if (str.at(0) == 'o') {
            if (!st.empty()) {
                cout << st.top() << endl;
                st.pop();
            }
            else cout << "empty" << endl;
        }
        if (str.at(0) == 'c') cout << st.size() << endl;
    }
}