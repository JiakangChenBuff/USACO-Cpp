#include <iostream>

#define MAX 510
#define INF 1000000000

int D, P, C, F, S, edges[MAX][3], dis[MAX], cycle, ans = INF;

int main()
{

    std::cin >> D >> P >> C >> F >> S;
    for (int i = 0; i < P; i++) {
        std::cin >> edges[i][0] >> edges[i][1];
        edges[i][2] = -D;
    }
    for (int i = 0; i < F; i++) {
        std::cin >> edges[P + i][0] >> edges[P + i][1] >> edges[P + i][2];
        edges[P + i][2] -= D;
    }

    for (int i = 1; i <= C; i++) {
        if (i == S) dis[i] = -D;
        else dis[i] = INF;
    }

    for (int i = 1; i < C; i++) {
        for (int j = 0; j < P + F; j++) {
            dis[edges[j][1]] = std::min(dis[edges[j][1]], dis[edges[j][0]] + edges[j][2]);
        }
    }

    for (int j = 0; j < P + F; j++) {
        cycle = (dis[edges[j][1]] > dis[edges[j][0]] + edges[j][2]) ? 1 : 0;
    }

    if (cycle) {
        std::cout << -1 << "\n";
    } else {
        for (int i = 1; i <= C; i++) {
            ans = std::min(ans, dis[i]);
        }
        std::cout << -1 * ans << "\n";
    }

    return 0;
}
