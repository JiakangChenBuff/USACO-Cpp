#include <iostream>
#include <cmath>
#include <algorithm>

#define MAX 2005


int N, A, B, pos[MAX];
double dp[MAX];

int main() {

    std::cin >> N >> A >> B;
    for (int i = 1; i <= N; i++)
        std::cin >> pos[i];
    std::sort(pos + 1, pos + N + 1);

    dp[1] = A;
    for (int i = 2; i <= N; i++) {

        dp[i] = A + dp[i - 1];

        for (int j = i - 1; j > 0; j--) {

            dp[i] = std::min(dp[i], dp[j - 1] + ((pos[i] - pos[j]) / 2.0) * B + A);

        }

    }

    if ((int) std::round(dp[N] * 2) % 2)
        printf("%.1f\n", dp[N]);
    else
        printf("%.0f\n", dp[N]);

    return 0;

}