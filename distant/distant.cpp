#include <bits/stdc++.h>

#define MAX 45
#define INF 1000000000

struct cmp {
    bool operator()(std::vector<int> a, std::vector<int> b) {
        return a[1] > b[1];
    }
};

int N, A, B, g[MAX][MAX], ans;

std::vector< std::vector< std::vector<int> > > adj(MAX * MAX);

int main()
{

    std::cin >> N >> A >> B;
    for (int i = 0; i < N; i++) {
        std::string line; std::cin >> line;
        for (int j = 0; j < N; j++) {
            g[i][j] = (line[j] == '(') ? 0 : 1;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != 0) {
                adj[N * i + j].push_back(std::vector<int> {N * (i - 1) + j, (g[i][j] == g[i - 1][j]) ? A : B});
            }
            if (i != N - 1) {
                adj[N * i + j].push_back(std::vector<int> {N * (i + 1) + j, (g[i][j] == g[i + 1][j]) ? A : B});
            }
            if (j != 0) {
                adj[N * i + j].push_back(std::vector<int> {N * i + j - 1, (g[i][j] == g[i][j - 1]) ? A : B});
            }
            if (j != N - 1) {
                adj[N * i + j].push_back(std::vector<int> {N * i + j + 1, (g[i][j] == g[i][j + 1]) ? A : B});
            }
        }
    }

    for (int i = 0; i < N * N; i++) {

        int dis[MAX * MAX] {0};
        for (int j = 0; j < N * N; j++) {
            if (j != i) {
                dis[j] = INF;
            }
        }
        bool vis[MAX * MAX] {false};

        std::priority_queue<std::vector<int>, std::vector< std::vector<int> >, cmp> q;
        q.push(std::vector<int> {i, 0});

        while (!q.empty()) {

            std::vector<int> curr = q.top();
            q.pop();

            if (vis[curr[0]]) {
                continue;
            }

            vis[curr[0]] = true;

            for (auto neighbor : adj[curr[0]]) {

                if (!vis[neighbor[0]] && dis[neighbor[0]] > dis[curr[0]] + neighbor[1]) {

                    dis[neighbor[0]] = dis[curr[0]] + neighbor[1];
                    q.push(std::vector<int> {neighbor[0], dis[neighbor[0]]});

                }

            }

        }

        for (int j = 0; j < N * N; j++) {
            ans = std::max(ans, dis[j]);
        }

    }

    std::cout << ans << "\n";

    return 0;
}
