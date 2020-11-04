#include <bits/stdc++.h>

#define MAX 35

int H, W, bounds[MAX][4], inCount[MAX], adj[MAX][MAX], wall[MAX][MAX], vis[MAX];
std::set< std::string > orders;
std::set<int> letters;

void getOrders(std::string order) {

    if (order.size() == letters.size()) {
        orders.insert(order);
        return;
    }

    for (int i : letters) {

        if (!vis[i] && inCount[i] == 0) {

            vis[i] = 1;
            for (int j : letters) {
                if (adj[i][j]) {
                    inCount[j]--;
                }
            }
            std::string new_order = order + (char) (i + 65);
            getOrders(new_order);

            vis[i] = 0;
            for (int j : letters) {
                if (adj[i][j]) {
                    inCount[j]++;
                }
            }
        }

    }

}

int main()
{

    for (int i = 0; i < MAX; i++) {
        bounds[i][0] = MAX;
        bounds[i][1] = MAX;
    }

    std::cin >> H >> W;

    for (int i = 0; i < H; i++) {
        std::string line; std::cin >> line;

        for (int j = 0; j < W; j++) {
            if (line[j] != '.') {
                letters.insert(line[j] - 65);
                bounds[line[j] - 65][0] = std::min(bounds[line[j] - 65][0], j);
                bounds[line[j] - 65][1] = std::min(bounds[line[j] - 65][1], i);
                bounds[line[j] - 65][2] = std::max(bounds[line[j] - 65][2], j);
                bounds[line[j] - 65][3] = std::max(bounds[line[j] - 65][3], i);
                wall[i][j] = line[j] - 65;
            } else {
                wall[i][j] = -1;
            }
        }
    }

    for (int i : letters) {

        for (int j = bounds[i][0]; j <= bounds[i][2]; j++) {

            if (wall[bounds[i][1]][j] != i) {
                adj[i][wall[bounds[i][1]][j]] = 1;
            }

            if (wall[bounds[i][3]][j] != i) {
                adj[i][wall[bounds[i][3]][j]] = 1;
            }

        }

        for (int j = bounds[i][1]; j <= bounds[i][3]; j++) {

            if (wall[j][bounds[i][0]] != i) {
                adj[i][wall[j][bounds[i][0]]] = 1;
            }

            if (wall[j][bounds[i][2]] != i) {
                adj[i][wall[j][bounds[i][2]]] = 1;
            }

        }

    }

    for (int a : letters) {

        for (int b : letters) {
            if (adj[a][b]) {
                inCount[b]++;
            }
        }

    }

    getOrders("");

    for (auto str : orders) {
        std::cout << str << "\n";
    }

    return 0;
}
