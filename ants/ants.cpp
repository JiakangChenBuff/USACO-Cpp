#include <iostream>

#define MAXT 1000
#define MAXN 100
#define MOD 1000000

int T, A, S, B, t[MAXT], dp[2][MAXT * MAXN + 1];

int main() {

    std::cin >> T >> A >> S >> B;
    for (int i = 0; i < A; i++) {
        int ty; std::cin >> ty;
        t[--ty]++;
    }

    dp[0][0] = 1;
    for (int j = 1; j <= t[0]; j++) {
        dp[0][j] = dp[0][j - 1] + 1;
    }
    for (int j = t[0] + 1; j <= MAXT * MAXN; j++) {
        dp[0][j] = dp[0][j - 1];
    }

    for (int i = 1; i < T; i++) {
        for (int j = 0; j <= MAXT * MAXN; j++) {
            if (j <= t[i]) {
                dp[i % 2][j] = dp[(i - 1) % 2][j];
            } else {
                dp[i % 2][j] = (dp[(i - 1) % 2][j] - dp[(i - 1) % 2][j - t[i] - 1]) % MOD;
            }
        }

        for (int j = 1; j <= MAXT * MAXN; j++) {
            dp[i % 2][j] = (dp[i % 2][j - 1] + dp[i % 2][j]) % MOD;
        }
    }

    std::cout << (((dp[(T - 1) % 2][B] - dp[(T - 1) % 2][S - 1]) % MOD) + MOD) % MOD << "\n";

    return 0;

}