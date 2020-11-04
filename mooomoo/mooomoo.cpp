#include <iostream>
#include <cmath>

#define MAX 6000005
#define INF 1000000000

int N, B, v[20], f[100], a[100], dp[MAX], ans;

int main() {

    std::cin >> N >> B;
    for (int i = 0; i < B; i++)
        std::cin >> v[i];
    for (int i = 0; i < N; i++)
        std::cin >> f[i];

    a[0] = f[0];
    for (int i = 1; i < N; i++)
        a[i] = f[i] - (f[i - 1] - ((f[i - 1]) ? 1 : 0));

    for (int i = 1; i <= MAX; i++)
        dp[i] = INF;

    for (int i = 1; i <= MAX; i++)
        for (int j = 0; j < B; j++)
            if (i - v[j] >= 0)
                dp[i] = std::min(dp[i], 1 + dp[i - v[j]]);

    ans = 0;
    for (int i = 0; i < N; i++) {
        if (dp[a[i]] == INF) {
            ans = -1;
            break;
        }
        ans += dp[a[i]];
    }
    
    std::cout << ans << "\n";

    return 0;

}