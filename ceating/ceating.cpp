#include <iostream>

#define MAXN 50000
#define MAXH 1000000
#define ll long long

ll N, D, c[MAXN];

bool possible(ll m) {

    ll total = 0;
    int cptr = 0;
    for (int d = 0; d < D; d++) {
        while (total < m && cptr < N) {
            total += c[cptr];
            cptr++;
        }
        if (total < m) {
            return false;
        }
        total /= 2;
    }

    return true;

}

int main() {

    std::cin >> N >> D;
    for (int i = 0; i < N; i++) {
        std::cin >> c[i];
    }

    ll l = 0;
    ll h = ((ll) MAXN) * MAXH;
    while (l <= h) {
        ll m = (l + h) / 2;
        if (!possible(m)) {
            h = m - 1;
        } else {
            l = m + 1;
        }
    }
    std::cout << h << "\n";

    return 0;

}