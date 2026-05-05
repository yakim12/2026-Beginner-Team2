#include <iostream>
#include <deque>
#include<vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    cin.ignore(); //개행문자 '\n' 제거 

    vector<int> v;
    deque<int> dq;

    for (int i = 0; i < n; i++) {//덱 초기화
        dq.push_back(i + 1); //{1, 2, 3, ... , n} 맨 위 ~ 맨 뒤
    }

    while (n--) {
        v.push_back(dq.front()); //가장 윗장을 플레이어에게
        dq.pop_front();

        if (!dq.empty()) {
            dq.push_back(dq.front()); //맨 위 카드를 맨 뒤로
            dq.pop_front();
        }
    }

    for (int x : v) {
        cout << x << ' ';
    }

    return 0;
}