#include <bits/stdc++.h>

#define MAXN 1010
#define ii std::pair<int, int>
#define f first
#define s second

int N, max[MAXN][MAXN], dp[MAXN][MAXN];
ii t[MAXN];

int main() {

    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> t[i].f >> t[i].s;
    }
    std::sort(t, t + N);

    int result = 0;

    for (int x = 0; x < 2; x++) {

        for (int i = N - 2; i >= 0; i--) {
            
            for (int j = N - 1; j > i; j--) {

                ii* k = std::lower_bound(t, t + N, ii {2 * t[j].f - t[i].f, -1});
                dp[i][j] = t[i].s + std::max(t[j].s, max[j][(k - t)]);
                max[i][j] = std::max(dp[i][j], max[i][j + 1]);
    
            }

        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                result = std::max(result, dp[i][j]);
                dp[i][j] = max[i][j] = 0;
            }
        }

        for (int i = 0; i < N; i++) {
            t[i].f = -t[i].f;
        }   
        std::reverse(t, t + N);

    }

    std::cout << result << '\n';

    return 0;

}