#include <iostream>
#include <cmath>

#define MAX 305
#define INF 1000000000

int N, adj[MAX][MAX], dis[MAX], vis[MAX], ans;

int main()
{

    std::cin >> N;
    for (int i = 0; i < N; i++) {
        int w; std::cin >> w;
        adj[i][N] = w; adj[N][i] = w;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> adj[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        dis[i] = INF;
    }
    for (int i = 0; i <= N; i++) {

        int min, vl = INF;
        for (int j = 0; j <= N; j++) {
            if (dis[j] < vl && !vis[j]) {
                min = j; vl = dis[j];
            }
        }

        vis[min] = true;
        ans += dis[min];
        for (int j = 0; j <= N; j++) {
            dis[j] = std::min(dis[j], adj[min][j]);
        }

    }
    std::cout << ans << "\n";

    return 0;
}
