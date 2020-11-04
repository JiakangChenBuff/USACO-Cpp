#include <iostream>
#include <queue>
#include <vector>

#define MAX 10010
#define INF 10000000000

int N, M;
std::vector< std::vector< std::vector<long long> > > adj(MAX);

struct cmp {
    bool operator()(std::vector<long long> a, std::vector<long long> b) {
        return a[1] > b[1];
    }
};

std::vector<long long> dijsktra(int a) {

    std::vector<long long> dis(MAX, 0);
    for (int i = 1; i < N; i++) {
        dis[i] = INF;
    }

    bool vis[MAX] {false};
    std::priority_queue<std::vector<long long>, std::vector< std::vector<long long> >, cmp> q;
    q.push(std::vector<long long> {N, 0});

    while (!q.empty()) {

        std::vector<long long> curr = q.top(); q.pop();
        if (vis[curr[0]]) {
            continue;
        }
        vis[curr[0]] = true;

        for (auto neighbor : adj[curr[0]]) {

            if (!vis[neighbor[0]] && dis[neighbor[0]] > dis[curr[0]] + neighbor[a]) {

                dis[neighbor[0]] = dis[curr[0]] + neighbor[a];
                q.push(std::vector<long long> {neighbor[0], dis[neighbor[0]]});

            }

        }

    }

    return dis;

}

int main()
{

    std::cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, p, q; std::cin >> a >> b >> p >> q;
        adj[b].push_back( std::vector<long long> {a, p, q, 0} );
    }

    std::vector<long long> dis1 = dijsktra(1);
    std::vector<long long> dis2 = dijsktra(2);

    for (int i = 1; i <= N; i++) {

        for (auto &neighbor : adj[i]) {

            if (dis1[neighbor[0]] - dis1[i] < neighbor[1]) {
                neighbor[3]++;
            }
            if (dis2[neighbor[0]] - dis2[i] < neighbor[2]) {
                neighbor[3]++;
            }

        }

    }

    std::vector<long long> dis3 = dijsktra(3);
    std::cout << dis3[1] << "\n";

    return 0;
}
