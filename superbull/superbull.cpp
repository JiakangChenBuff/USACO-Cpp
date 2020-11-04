#include <iostream>

#define MAX 2000

long long N, arr[MAX], adj[MAX][MAX], dis[MAX], vis[MAX], sum;

int main() {

    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            adj[i][j] = -1 * (arr[i] ^ arr[j]);
        }
    }

    for (int i = 0; i < N; i++)
        dis[i] = 100;
    dis[0] = 0;
    for (int i = 0; i < N; i++) {
        int min = -1, val = 100;
        for (int j = 0; j < N; j++) {
            if (!vis[j] && dis[j] < val) {
                min = j; val = dis[j];
            }
        }
        vis[min] = true;
        sum += val;
        for (int j = 0; j < N; j++) {
            if (!vis[j] && dis[j] > adj[min][j]) {
                dis[j] = adj[min][j];
            }
        }
    }
    std::cout << -1 * sum << "\n";

    return 0;
}