#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <utility>

#define MAXN 500
#define ii std::pair<int, int>
#define f first
#define s second

int N, field[MAXN][MAXN], arr[MAXN * MAXN], size[MAXN * MAXN];
std::vector< std::pair< int, ii > > edges;

int root(int i) {
    while (i != arr[i]) {
        arr[i] = arr[arr[i]];
        i = arr[i];
    }
    return i;
}

void un(int a, int b) {
    int ar = root(a);
    int br = root(b);
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
        for (int j = 0; j < N; j++) {
            std::cin >> field[i][j];
        }
    }
    for (int i = 0; i < N * N; i++) {
        arr[i] = i; size[i] = 1;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j != N - 1) {
                edges.push_back(std::make_pair(std::abs(field[i][j+1] - field[i][j]), std::make_pair(N * i + j, N * i + j + 1)));
            }
            if (i != N - 1) {
                edges.push_back(std::make_pair(std::abs(field[i+1][j] - field[i][j]), std::make_pair(N * (i+1) + j, N * i + j)));
            }
        }
    }
    std::sort(edges.begin(), edges.end());

    for (int i = 0; i < edges.size(); i++) {
        un(edges[i].s.f, edges[i].s.s);
        if (size[root(edges[i].s.f)] >= N * N / 2 + (N % 2) || size[root(edges[i].s.s)] >= N * N / 2 + (N % 2)) {
            std::cout << edges[i].f << '\n';
            break;
        }
    }

    return 0;

}