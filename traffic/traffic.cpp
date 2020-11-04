#include <iostream>
#include <vector>

#define MAX 5000
#define EDG 50000

int N, M, dp[MAX][2], edges[EDG][2], ans = 0;
std::vector< std::vector<int> > adj(MAX);
std::vector< std::vector<int> > par(MAX);

int main() {

    std::cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b; std::cin >> a >> b; --a; --b;
        adj[a].push_back(b);
        par[b].push_back(a);
        edges[i][0] = a;
        edges[i][1] = b;
    }

    for (int i = 0; i < N; i++) {
        if (!par[i].size()) dp[i][0]++;
    }

    for (int i = 0; i < N; i++) {

        for (int neigh : adj[i]) {
            dp[neigh][0] += dp[i][0];
        }

    }

    for (int i = 0; i < N; i++) {
        if (!adj[i].size()) dp[i][1]++;
    }

    for (int i = N - 1; i >= 0; i--) {

        for (int neigh : par[i]) {
            dp[neigh][1] += dp[i][1];
        }

    }

    for (int i = 0; i < M; i++) {
        ans = std::max(ans, dp[edges[i][0]][0] * dp[edges[i][1]][1]);
    }

    std::cout << ans << "\n";

    return 0;

}