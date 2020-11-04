#include <iostream>
#include <utility>
#include <cmath>
#include <queue>
#include <algorithm>
#include <vector>

#define MAX 1000
#define ii std::pair<int, int>
#define f first
#define s second
#define INF 1001000000

int N, E, dis[MAX][MAX], dp[MAX], ans;
ii patches[MAX];
std::vector< std::vector<int> > adj(MAX);

int main() {

    std::cin >> N >> E;

    for (int i = 0; i < N; i++) {

        int Q, D; std::cin >> Q >> D;
        patches[i] = std::make_pair(Q, i);
        
        for (int j = 0; j < D; j++) {
            int n; std::cin >> n; n--;
            adj[i].push_back(n);
        }
    }


    for (int i = 0; i < N; i++) {
        std::queue<int> q;      
        q.push(i);
        for (int j = 0; j < N; j++) {
            dis[i][j] = INF;
        }
        dis[i][i] = 0;
        while (!q.empty()) {
            int curr = q.front(); q.pop();
            for (int neigh : adj[curr]) {
                if (dis[i][neigh] == INF) {
                    dis[i][neigh] = dis[i][curr] + E;
                    q.push(neigh);
                }
            }
        }
    }

    std::sort(patches, patches + N);

    dp[patches[0].s] = patches[0].f;
    for (int i = 1; i < N; i++) {

        dp[patches[i].s] = patches[i].f;

        for (int j = 0; j < i; j++) {

            dp[patches[i].s] = std::max(dp[patches[i].s], patches[i].f - dis[patches[j].s][patches[i].s] + dp[patches[j].s]);
            
        }

    }

    for (int i = 0; i < N; i++) {

        ans = std::max(ans, dp[i]);

    }

    std::cout << ans << "\n";

    return 0;

}