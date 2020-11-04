#include <iostream>
#include <set>
#include <utility>
#include <algorithm>
#include <cmath>

#define MAXN 50000
#define ll long long
#define ii std::pair<ll, ll>
#define f first
#define s second

ll N, K, ans = 0;
ii c[MAXN];
std::multiset< ii > m;

int main() {

    std::cin >> N >> K;
    for (int i = 0; i < N; i++) {
        ll x, y; std::cin >> x >> y;
        c[i] = std::make_pair(x, y);
    }
    std::sort(c, c + N);

    m.insert(std::make_pair(c[0].s, c[0].f));
    for (int i = 1; i < N; i++) {
        for (auto it = m.begin(); it != m.end();) {
            if ((*it).s <= c[i].f - K) {
                it = m.erase(it);
            } else {
                ++it;
            }
        }
        auto it = std::upper_bound(m.begin(), m.end(), std::make_pair(c[i].s - K, (ll) 2000000));
        if (it != m.end() && (*it).f < c[i].s + K) {
            if (ans) {
                ans = -1;
                break;
            } else {
                ans = std::max(ans, (std::min((*it).s, c[i].f) - std::max((*it).s, c[i].f) + K) * (std::min((*it).f, c[i].s) - std::max((*it).f, c[i].s) + K));
            }
        }
        m.insert(std::make_pair(c[i].s, c[i].f));
    }

    std::cout << ans << '\n';

    return 0;

}