#include <iostream>
#include <algorithm>
#include <cmath>

#define MAX1 1000000
#define MAX2 1500
#define INF 2000000000

int N, S, D, pos[MAX2], dp[MAX1][2];

int main() {

    std::cin >> N >> S;
    D = (S - 1) / (N - 1);
    
    for (int i = 0; i < N; i++) {
        std::cin >> pos[i]; pos[i]--;
    }
    std::sort(pos, pos + N);

    dp[0][0] = std::abs(pos[0] - 0);
    for (int i = 1; i < N; i++) {
        for (int j = D * i; j < MAX1 && j <= (D + 1) * i; j++) {
            dp[j][i % 2] = INF;
            if (j != (D + 1) * i) {
                dp[j][i % 2] = std::min(dp[j][i % 2], std::abs(pos[i] - j) + dp[j - D][(i - 1) % 2]);
            }
            if (j != D * i) {
                dp[j][i % 2] = std::min(dp[j][i % 2], std::abs(pos[i] - j) + dp[j - D - 1][(i - 1) % 2]);
            }
        }
    }

    std::cout << dp[S - 1][(N - 1) % 2] << "\n";

    return 0;

}