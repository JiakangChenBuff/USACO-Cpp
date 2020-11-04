#include <iostream>

#define MAX 100

int N, M, adj[MAX][MAX][2], ans = -1;
bool dp[MAX][MAX * MAX + 1][2];

int main() {

    std::cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int A, B, C, D; std::cin >> A >> B >> C >> D;
        adj[A - 1][B - 1][0] = C;
        adj[A - 1][B - 1][1] = D;
    }

    dp[N - 1][0][0] = dp[N - 1][0][1] = 1;

    for (int i = N - 2; i >= 0; i--)
        for (int j = i + 1; j < N; j++)
            if (adj[i][j][0])
                for (int k = 0; k <= MAX * MAX; k++) {
                    if (dp[j][k][0])
                        dp[i][k + adj[i][j][0]][0] = 1;
                    if (dp[j][k][1])
                        dp[i][k + adj[i][j][1]][1] = 1;
                }

    for (int i = 0; i <= MAX * MAX; i++)
        if (dp[0][i][0] && dp[0][i][1]) {
            ans = i;
            break;
        }

    if (ans == -1)
        std::cout << "IMPOSSIBLE\n";
    else
        std::cout << ans << "\n";

    return 0;

}