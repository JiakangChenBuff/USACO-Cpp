#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <cmath>

#define MAXF 10000
#define DIS 1000000
#define ii std::pair<int, int>
#define f first
#define s second

int H, F, dis[MAXF], ans = MAXF + 100;
ii hh[MAXF];
std::vector< std::vector<int> > adj(MAXF);

int main() {

    std::cin >> H >> F;
    for (int i = 0; i < F; i++) {
        int x, y; std::cin >> x >> y;
        hh[i] = std::make_pair(x, y);
    }
    std::sort(hh, hh + F);
    for (int i = 0; i < F; i++) {
        ii* st = std::lower_bound(hh, hh + F, std::make_pair(hh[i].f - 1000, 0));
        while (st != hh + F && (*st).f <= hh[i].f + 1000) {
            if ((hh[i].f - (*st).f) * (hh[i].f - (*st).f) + (hh[i].s - (*st).s) * (hh[i].s - (*st).s) <= DIS) {
                adj[i].push_back(st - hh);
                adj[st - hh].push_back(i);
            }
            st++;
        }
    }

    for (int i = 0; i < F; i++) {
        dis[i] = MAXF + 100;
    }
    std::queue<int> q;
    for (int i = 0; i < F; i++) {
        if (hh[i].s <= 1000) {
            q.push(i);
            dis[i] = 1;
        }
    }
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        for (int n : adj[curr]) {
            if (dis[n] > dis[curr] + 1) {
                dis[n] = dis[curr] + 1;
                q.push(n);
            }
        }
    }
    
    for (int i = 0; i < F; i++) {
        if (hh[i].s >= H - 1000) {
            ans = std::min(ans, dis[i]);
        }
    }
    std::cout << ans << '\n';

    return 0;

}