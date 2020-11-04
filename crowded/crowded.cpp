#include <iostream>
#include <utility>
#include <algorithm>
#include <set>

#define MAXN 100000
#define ii std::pair<int, int>
#define f first
#define s second

int N, D, ans[MAXN];
ii cows[MAXN];
std::multiset< ii > byH;

int main() {

    std::cin >> N >> D;
    for (int i = 0; i < N; i++) {
        int x, h; std::cin >> x >> h;
        cows[i] = std::make_pair(x, h);
    }
    std::sort(cows, cows + N);
    byH.insert(std::make_pair(cows[0].s, cows[0].f));
    int j = 0;
    for (int i = 1; i < N; i++) {
        while (cows[j].f < cows[i].f - D) {
            auto it = byH.find(std::make_pair(cows[j].s, cows[j].f));
            byH.erase(it);
            j++;
        }
        if (byH.size() && (*(byH.rbegin())).f >= 2 * cows[i].s) ans[i]++;
        byH.insert(std::make_pair(cows[i].s, cows[i].f));
    }

    byH.clear();
    byH.insert(std::make_pair(cows[N - 1].s, cows[N - 1].f));
    j = N - 1;
    for (int i = N - 2; i >= 0; i--) {
        while (cows[j].f > cows[i].f + D) {
            auto it = byH.find(std::make_pair(cows[j].s, cows[j].f));
            byH.erase(it);
            j--;
            
        }
        if (byH.size() && (*(byH.rbegin())).f >= 2 * cows[i].s) ans[i]++;
        byH.insert(std::make_pair(cows[i].s, cows[i].f));
    }

    int fa = 0;
    for (int i = 0; i < N; i++) {
        if (ans[i] == 2) {
            fa++;
        }
    }
    std::cout << fa << '\n';

    return 0;

}