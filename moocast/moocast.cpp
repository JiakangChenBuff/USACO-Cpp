#include <bits/stdc++.h>

#define MAXN 1000
#define ii std::pair<int, int>
#define f first
#define s second

int N, coord[MAXN][2], arr[MAXN], size[MAXN];
std::vector< std::pair< int, ii > > edges;

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

    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> coord[i][0] >> coord[i][1];
    }
    for (int i = 0; i < N; i++) {
        arr[i] = i; size[i] = 1;
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            edges.push_back({(coord[i][0] - coord[j][0]) * (coord[i][0] - coord[j][0]) + (coord[i][1] - coord[j][1]) * (coord[i][1] - coord[j][1]), {i, j}});
        }
    }
    std::sort(edges.begin(), edges.end());

    for (auto edge : edges) {
        uf(edge.s.f, edge.s.s);
        if (size[root(edge.s.f)] == N) {
            std::cout << edge.f << '\n';
            break;
        }
    }

    return 0;

}