#include <iostream>
#include <cmath>

#define MAX 401

int N, p[MAX], adj[MAX][MAX], dp[MAX];

int recurse(int i) {

    if (dp[i])
        return dp[i];

    for (int j = 1; j <= N; j++)
        if (i != j && p[j] >= p[i] + adj[i][j])
            dp[i] = std::max(dp[i], ((i == 0) ? 0 : 1) + recurse(j));

    if (dp[i] == 0)
        dp[i] = 1;

    return dp[i];

}

int main() {

    std::cin >> N;
    for (int i = 1; i <= N; i++)
        std::cin >> p[i];
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            std::cin >> adj[i][j];
    for (int j = 1; j <= N; j++)
        adj[0][j] = adj[1][j];

    std::cout << recurse(0) << "\n";

    return 0;

}