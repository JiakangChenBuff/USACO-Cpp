#include <iostream>
#include <cmath>
#include <algorithm>

#define MAX 1005
#define INF 2000000000

int N, L, dp[MAX][MAX][2], pos[MAX], ans = INF;

int main() {

    std::cin >> N >> L;
    for (int i = 0; i < N; i++)
        std::cin >> pos[i];
    std::sort(pos, pos + N);

    for (int i = 0; i < N; i++)
        dp[i][i][0] = dp[i][i][1] = N * std::abs(L - pos[i]);

    for (int j = 1; j < N; j++)
        for (int i = 0; i + j < N; i++) {
            dp[i][i + j][0] = std::min(dp[i + 1][i + j][0] + (N - j) * (pos[i + 1] - pos[i]), dp[i + 1][i + j][1] + (N - j) * (pos[i + j] - pos[i]));
            dp[i][i + j][1] = std::min(dp[i][i + j - 1][1] + (N - j) * (pos[i + j] - pos[i + j - 1]), dp[i][i + j - 1][0] + (N - j) * (pos[i + j] - pos[i]));
        }

    std::cout << std::min(dp[0][N - 1][0], dp[0][N - 1][1]) << "\n";

    return 0;

}