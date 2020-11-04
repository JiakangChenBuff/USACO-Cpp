#include <iostream>
#include <cmath>

#define MAX 1005
#define INF 1000000000

int N, M, X, adj[MAX][MAX][2], dis[MAX][2], vis[MAX][2], ans;

void dijkstra(int a) {

    for (int i = 1; i <= N; i++) {
        if (i != X) {
            dis[i][a] = INF;
        }
    }

    for (int i = 1; i <= N; i++) {

        int min, val = INF;
        for (int j = 1; j <= N; j++) {
            if (!vis[j][a] && dis[j][a] < val) {
                min = j; val = dis[j][a];
            }
        }
        vis[min][a] = 1;

        for (int j = 1; j <= N; j++) {
            if (adj[min][j][a]) {
                dis[j][a] = std::min(dis[j][a], dis[min][a] + adj[min][j][a]);
            }
        }

    }

}

int main()
{

    std::cin >> N >> M >> X;
    for (int i = 0; i < M; i++) {
        int a, b, t; std::cin >> a >> b >> t;
        adj[a][b][0] = t; adj[b][a][1] = t;
    }

    dijkstra(0);
    dijkstra(1);

    for (int i = 1; i <= N; i++) {
        ans = std::max(ans, dis[i][0] + dis[i][1]);
    }
    std::cout << ans << "\n";

    return 0;
}
