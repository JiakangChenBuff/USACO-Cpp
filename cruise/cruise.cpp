#include <bits/stdc++.h>

#define MAXN 1010
#define MAXK 35

int N, M, K, dp[MAXN][MAXK], dir[MAXN], ans = 0;
std::vector< std::vector<int> > adj(MAXN);

int main()
{

    std::cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        int l, r; std::cin >> l >> r; l--; r--;
        adj[i].push_back(l); adj[i].push_back(r);
    }

    for (int i = 0; i < M; i++) {
        char c; std::cin >> c;
        dir[i] = (c == 'L') ? 0 : 1;
    }

    for (int i = 0; i < N; i++) {

        int curr = i;
        for (int j = 0; j < M; j++) {
            curr = adj[curr][dir[j]];
        }
        dp[i][0] = curr;

    }

    for (int j = 1; j <= (int) (std::log(K) / std::log(2)); j++) {

        for (int i = 0; i < N; i++) {

            dp[i][j] = dp[dp[i][j - 1]][j - 1];

        }

    }

    for (int j = 0; j <= (int) (std::log(K) / std::log(2)); j++) {

        if (K & (1 << j)) {
            ans = dp[ans][j];
        }

    }

    std::cout << ans + 1 << "\n";

    return 0;
}
