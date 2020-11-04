#include <iostream>
#include <cmath>

#define MAX 2001

int N, hay[21], dp[2][MAX][MAX], ans = 10000, sum = 0;

int main() {

    std::cin >> N;
    for (int i = 1; i <= N; i++)
        std::cin >> hay[i];

    dp[0][0][0] = 1;
    for (int i = 1; i <= N; i++)
        for (int j = 0; j < MAX; j++)
            for (int k = 0; k < MAX; k++) {

                if (!j && !k) dp[i % 2][0][0] = 1;

                dp[i % 2][j][k] = dp[(i - 1) % 2][j][k];
                if (j - hay[i] >= 0)
                    dp[i % 2][j][k] = dp[i % 2][j][k] || dp[(i - 1) % 2][j - hay[i]][k];
                if (k - hay[i] >= 0)
                    dp[i % 2][j][k] = dp[i % 2][j][k] || dp[(i - 1) % 2][j][k - hay[i]];

            }

    for (int i = 1; i <= N; i++)
        sum += hay[i];

    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            if (dp[N % 2][i][j])
                ans = std::min(ans, std::max( std::max(i, j), sum - i - j ));

    std::cout << ans << "\n";

    return 0;

}