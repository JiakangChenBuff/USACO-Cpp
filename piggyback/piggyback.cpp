#include <bits/stdc++.h>

#define MAX 40005
#define INF 2000000000LL
#define ll long long

ll B, E, P, N, M, dis[MAX][3];
std::vector< std::vector<int> > adj(MAX);

void bfs(int s) {

    int x = 0, i = 0;
    if (s == 0) {
        x = B;
    } else if (s == 1) {
        x = E;
        i = 1;
    } else {
        x = P;
        i = 2;
    }

    bool vis[MAX] {0};
    std::queue<int> q;
    vis[s] = 1; q.push(s); dis[s][i] = 0;
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        for (int n : adj[curr]) {
            if (!vis[n]) {
                dis[n][i] = dis[curr][i] + x;
                vis[n] = 1;
                q.push(n);
            }
        }
    }

}

int main() {

    std::cin >> B >> E >> P >> N >> M;
    for (int i = 0; i < M; i++) {
        int A, B; std::cin >> A >> B; --A; --B;
        adj[A].push_back(B); adj[B].push_back(A);
    }
    for (int i = 0; i < MAX; i++) {
        dis[i][0] = dis[i][1] = dis[i][2] = INF;
    }
    bfs(0); bfs(1); bfs(N - 1);
    ll min = 2 * INF;
    for (int i = 0; i < N; i++) {
        min = std::min(min, dis[i][0] + dis[i][1] + dis[i][2]);
    }
    std::cout << min << '\n';

    return 0;

}