#include <iostream>
#include <queue>
#include <vector>
#include <utility>

#define MAX 30
#define INF 1000
#define f first
#define s second

int M, N, sr, sc, er, ec, pond[MAX][MAX], vis[MAX][MAX], cost[MAX][MAX], dr[8] = {-2, -2, -1, 1, 2, 2, 1, -1}, dc[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
long long ways[MAX][MAX];
std::vector< std::pair<int, int> >  adj[MAX][MAX];

bool valid(int r, int c) {
    return r >= 0 && r < M && c >= 0 && c < N && pond[r][c] != 2;
}

int main() {

    std::cin >> M >> N;
    for (int r = 0; r < M; r++) {
        for (int c = 0; c < N; c++) {
            std::cin >> pond[r][c];
            if (pond[r][c] == 3) {
                pond[r][c] = 0; sr = r; sc = c;
            } else if (pond[r][c] == 4) {
                pond[r][c] = 0; er = r; ec = c;
            }
        }
    }

    for (int r = 0; r < M; r++) {
        for (int c = 0; c < N; c++) {
            if (!pond[r][c]) {
                std::queue< std::pair<int, int> > q;
                q.push( std::make_pair(r, c));
                vis[r][c] = 1;
                while (!q.empty()) {
                    auto curr = q.front(); q.pop();
                    for (int i = 0; i < 8; i++) {
                        int nr = curr.f + dr[i], nc = curr.s + dc[i];
                        if (valid(nr, nc) && !vis[nr][nc] && pond[nr][nc] == 0) {
                            adj[r][c].push_back(std::make_pair(nr, nc));
                            vis[nr][nc] = 1;
                        } else if (valid(nr, nc) && !vis[nr][nc] && pond[nr][nc] == 1) {
                            vis[nr][nc] = 1;
                            q.push( std::make_pair(nr, nc));
                        }
                    }
                }
                for (int r = 0; r < M; r++) {
                    for (int c = 0; c < N; c++) {
                        vis[r][c] = 0;
                    }
                }
            }
        }
    }

    std::queue< std::pair<int, int> > q;
    q.push( std::make_pair(sr, sc));
    ways[sr][sc] = 1;
    for (int r = 0; r < M; r++) {
        for (int c = 0; c < N; c++) {
            cost[r][c] = INF;
        }
    }
    cost[sr][sc] = 0;
    while (!q.empty()) {
        auto curr = q.front(); q.pop();
        for (auto n : adj[curr.f][curr.s]) {
            if (cost[n.f][n.s] == INF) {
                cost[n.f][n.s] = cost[curr.f][curr.s] + 1;
                ways[n.f][n.s] += ways[curr.f][curr.s];
                q.push(std::make_pair(n.f, n.s));
            } else if (cost[n.f][n.s] == cost[curr.f][curr.s] + 1) {
                ways[n.f][n.s] += ways[curr.f][curr.s];
            }
        }
    }

    if (cost[er][ec] == INF) {
        std::cout << -1 << "\n";
    } else {
        std::cout << cost[er][ec] - 1 << "\n";
        std::cout << ways[er][ec] << "\n";
    }

    return 0;
}
