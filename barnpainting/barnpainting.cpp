#include <iostream>
#include <cmath>
#include <vector>
#include <queue>

#define MAX 100000
#define MOD 1000000007
#define ll long long

ll N, K, dp[MAX][3], color[MAX], vis[MAX];
std::vector< std::vector<int> > init(MAX);
std::vector< std::vector<int> > child(MAX);

ll recurse(int i, int c) {

    if (dp[i][c] != -1) {
        return dp[i][c];
    }

    if (color[i] != -1 && color[i] != c) {
        return 0;
    }

    dp[i][c] = 1;
    for (int ch : child[i]) {

        dp[i][c] = (dp[i][c] * ((recurse(ch, (c + 1) % 3) + recurse(ch, (c + 2) % 3)) % MOD)) % MOD;

    }

    return dp[i][c] % MOD;

}

int main() {

    std::cin >> N >> K;

    for (int i = 0; i < N - 1; i++) {
        int x, y; std::cin >> x >> y; --x; --y;
        init[x].push_back(y);
        init[y].push_back(x);
    }

    for (int i = 0; i < N; i++) {
        color[i] = -1;
    }
    for (int i = 0; i < K; i++) {
        int b, c; std::cin >> b >> c; --b; --c;
        color[b] = c;
    }

    std::queue<int> q;
    vis[0] = 1;
    q.push(0);
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        for (int neigh : init[curr]) {
            if (!vis[neigh]) {
                child[curr].push_back(neigh);
                q.push(neigh);
                vis[neigh] = 1;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        dp[i][0] = dp[i][1] = dp[i][2] = -1;
    }

    std::cout << ((recurse(0, 0) + recurse(0, 1)) % MOD + recurse(0, 2)) % MOD << "\n";
    
    return 0;

}