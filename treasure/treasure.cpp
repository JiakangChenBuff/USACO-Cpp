#include <iostream>
#include <cmath>

#define MAXN 5001

int N, c[MAXN], dp[2][MAXN], ps[MAXN];

int main() {

    std::cin >> N;
    for (int i = 1; i <= N; i++) {
        std::cin >> c[i];
    }

    for (int i = 1; i <= N; i++) {
        ps[i] = ps[i - 1] + c[i];
    }

    for (int i = 1; i <= N; i++) {
        dp[0][i] = c[i];
    }
    for (int j = 1; j < N; j++) {
        for (int i = 1; i + j <= N; i++) {
            dp[j % 2][i] = std::max(c[i + j] + ps[i + j - 1] - ps[i - 1] - dp[(j - 1) % 2][i], c[i] + ps[i + j] - ps[i] - dp[(j - 1) % 2][i + 1]);
        }
    }
    std::cout << dp[(N - 1) % 2][1] << "\n";

    return 0;

}