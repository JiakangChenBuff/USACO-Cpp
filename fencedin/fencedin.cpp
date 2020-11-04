#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <utility>

#define MAX 2010
#define INF 2000000000

struct cmp {
    bool operator()(std::pair<int, int> a, std::pair<int, int> b) {
        return a.second > b.second;
    }
};

int A, B, n, m, h[MAX], w[MAX], vis[MAX * MAX], dis[MAX * MAX];
long long ans = 0;
std::priority_queue< std::pair<int, int> , std::vector< std::pair<int, int> >, cmp> q;

int main()
{

    std::cin >> A >> B >> n >> m;

    w[0] = 0; w[n + 1] = A;
    for (int i = 1; i <= n; i++) {
        std::cin >> w[i];
    }
    std::sort(w, w + n + 1);

    h[0] = 0; h[m + 1] = B;
    for (int i = 1; i <= m; i++) {
        std::cin >> h[i];
    }
    std::sort(h, h + m + 1);

    for (int i = 0; i <= n; i++) {
        w[i] = w[i + 1] - w[i];
    }
    for (int i = 0; i <= m; i++) {
        h[i] = h[i + 1] - h[i];
    }

    for (int i = 1; i < (m + 1) * (n + 1); i++) {
        dis[i] = INF;
    }

    q.push(std::make_pair(0, 0));
    while (!q.empty()) {

        auto curr = q.top(); q.pop();
        if (vis[curr.first]) {
            continue;
        }
        vis[curr.first] = 1;
        ans += curr.second;

        if (curr.first >= n + 1) {

            int nextNode = curr.first - n - 1; int toDis = w[curr.first % (n + 1)];
            if (!vis[nextNode] && dis[nextNode] > toDis) {
                dis[nextNode] = toDis;
                q.push(std::make_pair(nextNode, toDis));
            }

        }

        if (curr.first < m * (n + 1)) {

            int nextNode = curr.first + n + 1; int toDis = w[curr.first % (n + 1)];
            if (!vis[nextNode] && dis[nextNode] > toDis) {
                dis[nextNode] = toDis;
                q.push(std::make_pair(nextNode, toDis));
            }

        }

        if (curr.first % (n + 1) != 0) {

            int nextNode = curr.first - 1; int toDis = h[curr.first / (n + 1)];
            if (!vis[nextNode] && dis[nextNode] > toDis) {
                dis[nextNode] = toDis;
                q.push(std::make_pair(nextNode, toDis));
            }

        }

        if (curr.first % (n + 1) != n) {

            int nextNode = curr.first + 1; int toDis = h[curr.first / (n + 1)];
            if (!vis[nextNode] && dis[nextNode] > toDis) {
                dis[nextNode] = toDis;
                q.push(std::make_pair(nextNode, toDis));
            }

        }

    }

    std::cout << ans << "\n";

    return 0;
}
