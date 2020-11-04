#include <iostream>
#include <algorithm>
#include <utility>

#define MAXN 100000
#define INF 2000000000
#define ii std::pair<int, int>
#define f first
#define s second

int L, N, ans = 0, vc = 1;
ii m[MAXN + 5];

int main() {

    std::cin >> L >> N;
    for (int i = 0; i < N; i++) {
        int T, S; std::cin >> T >> S;
        m[i] = std::make_pair(T, S);
    }
    m[N] = std::make_pair(0, 0);
    m[N + 1] = std::make_pair(L, INF);
    std::sort(m, m + N + 2);

    for (int i = N - 1; i > 0; i--) {
        m[i].s = std::min(m[i + 1].s + m[i + 1].f - m[i].f, m[i].s);
    }

    for (int i = 1; i <= N + 1; i++) {
        if (m[i].f - m[i - 1].f + vc <= m[i].s) {
            vc += m[i].f - m[i - 1].f;
            ans = std::max(ans, vc);
        } else {
            int x = (m[i].f - m[i - 1].f + m[i].s - vc) / 2;
            ans = std::max(ans, vc + x);
            vc = m[i].s;
        }
    }

    std::cout << ans << '\n';

    return 0;

}