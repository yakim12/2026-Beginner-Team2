#include <iostream>
#include <vector>

using namespace std;

int N, M;
long long total_count = 0;
char stack_arr[30];
char out_arr[30];
int top_idx = -1;
int out_idx = 0;

// 조합(Combination)을 이용해 카탈란 수를 구하는 함수 (N=26까지 대응)
long long get_catalan(int n) {
    if (n <= 1) return 1;

    // n이 커질수록 숫자가 매우 커지므로 DP를 사용하여 계산
    // C(n) = sigma(i=0 to n-1) C(i) * C(n-1-i)
    vector<long long> C(n + 1, 0);
    C[0] = 1;
    C[1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            C[i] += C[j] * C[i - 1 - j];
        }
    }
    return C[n];
}

void solve(int n) {
    if (out_idx == N) {
        for (int i = 0; i < N; i++) cout << out_arr[i];
        cout << '\n';
        return;
    }

    if (M == 1) { // 오름차순: Push 우선
        if (n < N) {
            stack_arr[++top_idx] = (char)('A' + n);
            solve(n + 1);
            top_idx--;
        }
        if (top_idx >= 0) {
            char temp = stack_arr[top_idx--];
            out_arr[out_idx++] = temp;
            solve(n);
            out_idx--;
            stack_arr[++top_idx] = temp;
        }
    }
    else { // 내림차순: Pop 우선
        if (top_idx >= 0) {
            char temp = stack_arr[top_idx--];
            out_arr[out_idx++] = temp;
            solve(n);
            out_idx--;
            stack_arr[++top_idx] = temp;
        }
        if (n < N) {
            stack_arr[++top_idx] = (char)('A' + n);
            solve(n + 1);
            top_idx--;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> N >> M)) return 0;

    // 1. 수학적으로 전체 개수만 먼저 계산 (시간 복잡도 O(N^2))
    total_count = get_catalan(N);
    cout << total_count << "\n";

    // 2. 개수가 65536 이하일 때만 실제 탐색 수행 (O(Catalan) 시간 복잡도)
    if (total_count <= 65536) {
        solve(0);
    }

    return 0;
}