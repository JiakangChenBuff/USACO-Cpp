#include <bits/stdc++.h>

#define MAXN 100005

int N, bit[MAXN], ls[MAXN];

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

int main() {

    std::cin >> N;
    int ans = 0;
    for (int i = 0; i < 2 * N; i++) {
        int x; std::cin >> x;
        if (ls[x]) {
            update(ls[x], -1);
            ans += query(i) - query(ls[x]);
        } else {
            ls[x] = i + 1;
            update(i + 1, 1);
        }
    }
    std::cout << ans << '\n';

    return 0;

}