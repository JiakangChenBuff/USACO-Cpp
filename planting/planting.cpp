#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

#define MAXN 1000
#define ll long long
#define ii std::pair<ll, ll>
#define f first
#define s second

ll N, rec[MAXN][4], a[MAXN], ans = 0;
std::vector< std::pair< ll, ii > > e;

int main() {

    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> rec[i][0] >> rec[i][1] >> rec[i][2] >> rec[i][3];
        e.push_back(std::make_pair(rec[i][0], std::make_pair(i, 1)));
        e.push_back(std::make_pair(rec[i][2], std::make_pair(i, -1)));
    }
    std::sort(e.begin(), e.end());

    a[e[0].s.f] = 1;
    for (int i = 1; i < e.size(); i++) {
        ll dx = e[i].f  - e[i - 1].f;
        std::vector< ii > y;
        for (int j = 0; j < N; j++) {
            if (a[j] == 1) {
                y.push_back(std::make_pair(rec[j][1], -1));
                y.push_back(std::make_pair(rec[j][3], 1));
            }
        }
        std::sort(y.begin(), y.end());
        ll d = 1, t = 0;
        for (int j = 1; j < y.size(); j++) {
            t += ((d) ? 1 : 0) * (y[j].f - y[j - 1].f);
            d += y[j].s;
        }
        ans += dx * t;
        a[e[i].s.f] = e[i].s.s;
    }

    std::cout << ans << '\n';

    return 0;

}