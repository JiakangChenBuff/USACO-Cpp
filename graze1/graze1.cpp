#include <iostream>
#include <cmath>

#define MAXN 10000
#define MAXL 100000

int N, L, pos[MAXN], dp[2][MAXL], D;

int main() {

    std::cin >> N >> L;
    for (int i = 0; i < N; i++) {
        std::cin >> pos[i];
    }

    D = (L + 1) / N;

    dp[0][0] = pos[0];
    for (int i = 1; i < N; i++) {

        for (int j = D * i; j <= L && j <= (D + 1) * i; j++) {

            int cost = std::abs(j - pos[i]);
            dp[i % 2][j] = -1;
            if (j - D >= D * (i - 1) && j - D <= (D + 1) * (i - 1)) {
                dp[i % 2][j] = dp[(i - 1) % 2][j - D] + cost;
            }
            if (j - D - 1 >= D * (i - 1) && j - D - 1 <= (D + 1) * (i - 1)) {
                if (dp[i % 2][j] == -1) {
                    dp[i % 2][j] = dp[(i - 1) % 2][j - D - 1] + cost;
                } else {
                    dp[i % 2][j] = std::min(dp[i % 2][j], dp[(i - 1) % 2][j - D - 1] + cost);
                }
            }
            
        }

    }

    std::cout << dp[(N - 1) % 2][L] << "\n";

    return 0;
}