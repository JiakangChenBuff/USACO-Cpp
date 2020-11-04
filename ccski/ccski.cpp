#include <bits/stdc++.h>

#define MAX 510

int M, N, g[MAX][MAX], w[MAX][MAX], low = 0, high = 1000000000, dx[4] {-1, 0, 1, 0}, dy[4] {0, 1, 0, -1};

bool works(int x, int y) {
    return x >= 0 && x < M && y >= 0 && y < N;
}

bool possible(int d) {

    bool vis[MAX][MAX] {false};
    std::queue< std::vector<int> > q;
    bool found = false;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (w[i][j] && !found) {
                vis[i][j] = true;
                q.push(std::vector<int> {i, j});
                found = true;
            }
        }
    }

    while (!q.empty()) {

        std::vector<int> curr = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            if (works(curr[0] + dx[i], curr[1] + dy[i]) &&
                !vis[curr[0] + dx[i]][curr[1] + dy[i]] &&
                std::abs(g[curr[0]][curr[1]] - g[curr[0] + dx[i]][curr[1] + dy[i]]) <= d) {

                vis[curr[0] + dx[i]][curr[1] + dy[i]] = true;
                q.push(std::vector<int> {curr[0] + dx[i], curr[1] + dy[i]});

            }
        }

    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (w[i][j] && !vis[i][j]) {
                return false;
            }
        }
    }

    return true;

}

int main()
{

    std::cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> g[i][j];
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> w[i][j];
        }
    }

    while (low <= high) {
        int mid = (low + high) / 2;

        if (possible(mid)) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    std::cout << low << "\n";

    return 0;
}
