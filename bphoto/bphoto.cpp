#include <bits/stdc++.h>

#define MAXN 100000
#define f first
#define s second

int N, bit[MAXN + 1];
std::pair<int, int> h[MAXN];

void update(int i, int v) {
    while (i <= MAXN) {
        bit[i] += v;
        i += i & (-i);
    }
}

int query(int i) {
    int sum = 0;
    while (i > 0) {
        sum += bit[i];
        i -= i & (-i);
    }
    return sum;
}

bool cmp(std::pair<int, int> a, std::pair<int, int> b) {
    return a.f > b.f;
}

int main() {

    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> h[i].f; h[i].s = i;
    }
    std::sort(h, h + N, cmp);
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int L = query(h[i].s); int R = i - L;
        int max = std::max(L, R), min = std::min(L, R);
        if (2 * min < max) {
            ans++;
        }
        update(h[i].s + 1, 1);
    }
    std::cout << ans << '\n';

    return 0;

}