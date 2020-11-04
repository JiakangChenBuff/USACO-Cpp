#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

#define INF 100000000

struct cmp {
    bool operator()(std::vector<int> a, std::vector<int> b) {
        return a[5] > b[5];
    }
};

std::unordered_map<int, int> m;
int trans[110][6], dis[6][6][6][6][6], ans[5], cnt, s, b;
std::priority_queue< std::vector<int>, std::vector< std::vector<int> >, cmp> q;

bool valid(int u, int w, int x, int y, int z) {
    return u < 6 && w < 6 && x < 6 && y < 6 && z < 6;
}

int main() {

    std::cin >> s;
    for (int i = 0; i < s; i++) {
        int n; std::cin >> n;
        for (int j = 0; j < n; j++) {
            int c, k; std::cin >> c >> k;
            if (!m.count(c)) {
                m.emplace(c, cnt++);
            }
            trans[i][m[c]] = k;
        }
        std::cin >> trans[i][5];
    }

    std::cin >> b;
    for (int i = 0; i < b; i++) {
        int c, k, p; std::cin >> c >> k >> p;
        if (!m.count(c)) {
            m.emplace(c, cnt++);
        }
        trans[s + i][m[c]] = 1;
        trans[s + i][5] = p;
        ans[m[c]] = k;
    }

    for (int h = 0; h < 6; h++) 
        for (int i = 0; i < 6; i++) 
            for (int j = 0; j < 6; j++) 
                for (int k = 0; k < 6; k++) 
                    for (int l = 0; l < 6; l++) 
                        dis[h][i][j][k][l] = INF;
    dis[0][0][0][0][0] = 0;
    q.push(std::vector<int> {0, 0, 0, 0, 0, 0});

    while (!q.empty()) {
        auto curr = q.top(); q.pop();

        if (dis[curr[0]][curr[1]][curr[2]][curr[3]][curr[4]] < curr[5]) continue;

        for (int i = 0; i < s + b; i++) {
            int u = curr[0] + trans[i][0], w = curr[1] + trans[i][1], x = curr[2] + trans[i][2], y = curr[3] + trans[i][3], z = curr[4] + trans[i][4];
            if (valid(u, w, x, y, z) && dis[u][w][x][y][z] > dis[curr[0]][curr[1]][curr[2]][curr[3]][curr[4]] + trans[i][5]) {
                dis[u][w][x][y][z] = dis[curr[0]][curr[1]][curr[2]][curr[3]][curr[4]] + trans[i][5];
                q.push(std::vector<int> {u, w, x, y, z, dis[u][w][x][y][z]});
            }
        }

    }

    std::cout << dis[ans[0]][ans[1]][ans[2]][ans[3]][ans[4]] << "\n";

    return 0;
}

