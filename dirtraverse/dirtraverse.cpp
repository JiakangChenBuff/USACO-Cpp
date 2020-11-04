#include <iostream>
#include <string>
#include <vector>
#include <queue>

#define MAX 100000
#define ll long long

ll N, cnt[MAX], n_files[MAX], ans;
std::string names[MAX];
std::vector< std::vector<int> > adj(MAX);
std::queue<int> q;

ll count_files(int x) {

    ll count = 0;
    for (int c : adj[x]) {
        if (adj[c].size()) {
            count += count_files(c);
        } else {
            count++;
        }
    }
    n_files[x] = count;
    return count;

}

int main() {

    std::cin >> N;
    for (int i = 0; i < N; i++) {

        std::cin >> names[i];
        int m; std::cin >> m;
        for (int j = 0; j < m; j++) {
            int x; std::cin >> x; --x;
            adj[i].push_back(x);
        }

    }

    q.push(0);
    ll count = 0;
    while (!q.empty()) {
        int par = q.front(); q.pop();
        for (int c : adj[par]) {
            if (adj[c].size()) {
                cnt[c] = (cnt[par] + names[c].size() + 1);
                q.push(c);
            } else {
                count += (cnt[par] + names[c].size());
            }
        }
    }
    for (int i = 1; i < N; i++) {
        cnt[i] = 0;
    }
    cnt[0] = count;
    
    count_files(0);

    ans = cnt[0];
    q.push(0);
    while (!q.empty()) {
        int par = q.front(); q.pop();
        for (int c : adj[par]) {
            if (adj[c].size()) {
                cnt[c] = cnt[par] - ((ll) (names[c].size() + 1) * n_files[c]) + 3 * (n_files[0] - n_files[c]);
                ans = std::min(ans, cnt[c]);
                q.push(c);
            }
        }
    }
    std::cout << ans << "\n";

    return 0;

}