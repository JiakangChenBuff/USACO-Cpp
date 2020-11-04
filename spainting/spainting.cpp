#include <iostream>

#define MAXN 1000000
#define MOD 1000000007
#define ll long long

ll N, M, K, dp[MAXN][2], cmp, tot = 1;

int main() {

    std::cin >> N >> M >> K;
    dp[0][0] = dp[0][1] = M;
    for (int i = 1; i < K - 1; i++) {
        dp[i][0] = (dp[i - 1][0] * M) % MOD;
        dp[i][1] = (dp[i - 1][1] + dp[i][0]) % MOD;
    }
    dp[K - 1][0] = (dp[K - 2][1] * (M - 1)) % MOD;
    dp[K - 1][1] = (dp[K - 2][1] + dp[K - 1][0]) % MOD;

    for (int i = K; i < N; i++) {
        dp[i][0] = ((dp[i - 1][1] - dp[i - K][1]) * (M - 1)) % MOD;
        dp[i][1] = (dp[i - 1][1] + dp[i][0]) % MOD;
    }

    cmp = ((dp[N - 1][0] < 0) ? dp[N - 1][0] + MOD : dp[N - 1][0]);
    for (int i = 0; i < N; i++) {
        tot = (tot * M) % MOD;
    }
    std::cout << ((tot - cmp) % MOD < 0 ? (tot - cmp) % MOD + MOD : (tot - cmp) % MOD) << "\n";

    return 0;   

}