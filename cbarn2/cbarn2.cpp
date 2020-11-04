#include <iostream>
#include <cmath>

#define MAXN 100
#define MAXK 7
#define ll long long
#define INF 1000000000000

ll N, K, c[MAXN], ans = INF;

int main() {

    std::cin >> N >> K;
    for (int i = 0; i < N; i++) {
       std::cin >> c[i];
    }

    for (int i = 0; i < N; i++) {

        ll dp[MAXN][MAXK + 1];
        for (int j = 0; j < N; j++) {
            for (int k = 0; k <= K; k++) {
                dp[j][k] = INF;
            }
        }

        for (int j = 1; j <= K; j++) {
            dp[(i + N - 1) % N][j] = 0;
        }

        for (int j = i; j <= i + N - 1; j++) {
            dp[j % N][1] = 0;
            for (int k = j + 1; k <= i + N - 1; k++) {
                dp[j % N][1] += c[k % N] * (k - j);
            }
        }

        for (int j = i + N - 2; j >= i; j--) {
            
            for (int k = 2; k <= K; k++) {

                ll sum = 0;
                for (int l = j + 1; l <= i + N - 1; l++) {

                    dp[j % N][k] = std::min(dp[j % N][k], sum + dp[l % N][k - 1]);
                    sum += c[l % N] * (l - j);

                }

            }

        }
        
        ans = std::min(ans, dp[i % N][K]);

    }

    std::cout << ans << "\n";

    return 0;

}