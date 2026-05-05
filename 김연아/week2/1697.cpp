#include <iostream>
#include <queue>
#include <string>  
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue<int> qu;

    int n;
    cin >> n;
    cin.ignore(); //개행문자 '\n' 제거 

    char cmd;
    while (n--) {
        cin >> cmd;
        if (cmd == 'i') {
            int val;
            cin >> val;
            qu.push(val);
        }

        if (cmd == 'o') {
            if (!qu.empty()) {
                cout << qu.front() << endl;
                qu.pop();
            }
            else cout << "empty" << endl;
        }
        if (cmd == 'c') cout << qu.size() << endl;
    }

    return 0;
}