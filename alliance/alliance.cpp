#include <bits/stdc++.h>

#define MOD 1000000007
#define MAX 100010

int N, M, edges[MAX][2], group[MAX], vis[MAX], comp;
std::vector< std::vector<int> > adj(MAX), components(MAX);
long long ans = 1;


int main()
{

    std::cin >> N >> M;

    for (int i = 0; i < M; i++) {
        std::cin >> edges[i][0] >> edges[i][1];
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    for (int i = 1; i <= N; i++) {

        if (vis[i]) continue;

        std::queue<int> q;
        q.push(i); vis[i] = 1; group[i] = ++comp;
        while (!q.empty()) {
            int curr = q.front(); q.pop();
            for (auto neigh : adj[curr]) {
                if (!vis[neigh]) {
                    vis[neigh] = 1;
                    group[neigh] = comp;
                    q.push(neigh);
                }
            }
        }

    }

    for (int i = 1; i <= comp; i++) {
        components[i].push_back(0); components[i].push_back(0);
    }
    for (int i = 1; i <= N; i++) {
        components[group[i]][0]++;
    }
    for (int i = 0; i < M; i++) {
        components[group[edges[i][0]]][1]++;
    }

    for (int i = 1; i <= comp; i++) {
        if (components[i][0] < components[i][1]) {
            std::cout << 0 << "\n"; break;
        } else if (components[i][0] == components[i][1]) {
            ans = (ans * 2) % MOD;
        } else {
            ans = (ans * components[i][0]) % MOD;
        }
    }

    std::cout << ans << "\n";

    return 0;
}
