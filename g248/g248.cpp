#include <iostream>

int N, dp[250][250], arr[250], ans = 0;

int main() {

    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }

    for (int i = 0; i < N; i++) {
        dp[i][i] = arr[i];
    }

    for (int x = 1; x < N; x++) {
        for (int i = 0; i + x < N; i++) {

            for (int j = 0; j < x; j++) {

                dp[i][i + x] = std::max(dp[i][i + x], (dp[i][i + j] == dp[i + j + 1][i + x]) ? dp[i][i + j] + 1 : -1);

            }

        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            ans = std::max(ans, dp[i][j]);
        }
    }

    std::cout << ans << "\n";

    return 0;

}