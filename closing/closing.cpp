#include <bits/stdc++.h>

#define MAXN 200000

int N, M, vis[MAXN], c[MAXN], arr[MAXN], size[MAXN];
std::string ans[MAXN];
std::vector< std::vector<int> > adj(MAXN);

int root(int i) {
    while (i != arr[i]) {
        arr[i] = arr[arr[i]];
        i = arr[i];
    }
    return i;
}

void uf(int a, int b) {
    int ar = root(a); int br = root(b);
    if (ar != br) {
        if (size[ar] > size[br]) {
            arr[br] = ar;
            size[ar] += size[br];
        } else {
            arr[ar] = br;
            size[br] += size[ar];
        }
    }
}

int main() {

    std::cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b; std::cin >> a >> b; --a; --b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    for (int i = 0; i < N; i++) {
        std::cin >> c[i]; --c[i];
        arr[i] = i; size[i] = 1;
    }
    for (int i = N - 1; i >= 0; i--) {
        vis[c[i]] = 1;
        for (auto n : adj[c[i]]) {
            if (vis[n]) {
                uf(c[i], n);
            }
        }
        if (size[root(c[i])] == N - i) {
            ans[i] = "YES";
        } else {
            ans[i] = "NO";
        }
    }

    for (int i = 0; i < N; i++) {
        std::cout << ans[i] << '\n';
    }

    return 0;

}