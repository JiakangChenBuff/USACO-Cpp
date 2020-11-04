#include <iostream>

#define MAXN 100
#define MAXT 16

int N, M, T, R1, C1, R2, C2, dp[MAXN][MAXN][MAXT], a[MAXN][MAXN], dr[4] {-1, 0, 1, 0}, dc[4] {0, 1, 0, -1};

bool valid(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < M && !a[r][c];
}

int rec(int r, int c, int t) {
    if (dp[r][c][t] != -1) {
        return dp[r][c][t];
    }
    if (!t && r == R1 && c == C1) {
        dp[r][c][t] = 1;
    } else if (!t) {
        dp[r][c][t] = 0;
    } else {
        dp[r][c][t] = 0;
        for (int i = 0; i < 4; i++) {
            if (valid(r + dr[i], c + dc[i]))
                dp[r][c][t] += rec(r + dr[i], c + dc[i], t - 1);
        }
    }
    return dp[r][c][t];
}

int main() {

    std::cin >> N >> M >> T;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            char ch; std::cin >> ch;
            a[r][c] = (ch == '*') ? 1 : 0;
        }
    }
    std::cin >> R1 >> C1 >> R2 >> C2; --R1; --C1; --R2; --C2;

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            for (int t = 0; t <= T; t++) {
                dp[r][c][t] = -1;
            }
        }
    }

    std::cout << rec(R2, C2, T) << "\n";

    return 0;

}