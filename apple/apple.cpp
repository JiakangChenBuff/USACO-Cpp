#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <utility>

#define MAXP 100000
#define ll long long
#define ii std::pair<ll, ll>
#define f first
#define s second
#define INF 2000000010

struct cmp {
    bool operator() (ii a, ii b) {
        return a.f > b.f;
    }
};

ll C, P, PB, PA1, PA2, dis[MAXP][2], vis[MAXP][2]; 
std::vector< std::vector< ii > > adj(MAXP);

void dijkstra(int st, int x) {

    std::priority_queue<ii, std::vector< ii >, cmp> q;
    for (int i = 0; i < P; i++) {
        if (i != st) dis[i][x] = INF;
    }

    q.push(ii {0, st});
    while (!q.empty()) {
        ii curr = q.top(); q.pop();
        if (vis[curr.s][x]) {
            continue;
        }
        vis[curr.s][x] = 1;
        for (ii n : adj[curr.s]) {
            if (dis[n.s][x] > dis[curr.s][x] + n.f) {
                dis[n.s][x] = dis[curr.s][x] + n.f;
                q.push(ii {dis[n.s][x], n.s});
            }
        }
    }

}

int main() {

    std::cin >> C >> P >> PB >> PA1 >> PA2; PB--; PA1--; PA2--;
    for (int i = 0; i < C; i++) {
        int a, b, d; std::cin >> a >> b >> d; a--; b--;
        adj[a].push_back(ii {d, b});
        adj[b].push_back(ii {d, a});
    }

    dijkstra(PA1, 0);
    dijkstra(PA2, 1);

    std::cout << std::min(std::min(dis[PB][0] + dis[PA2][0], dis[PB][1] + dis[PA1][1]), std::min(2 * dis[PB][0] + dis[PB][1], 2 * dis[PB][1] + dis[PB][0])) << "\n";

    return 0;

}