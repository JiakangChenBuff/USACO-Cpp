#include <iostream>
#include <utility>
#include <algorithm>

#define ii std::pair<int, int>
#define f first
#define s second

int N, C, ans = 0, st = -1;
ii coins[20];

int main() {

    std::cin >> N >> C;
    for (int i = 0; i < N; i++) {
        int v, b; std::cin >> v >> b;
        coins[i] = std::make_pair(v, b);
    }
    std::sort(coins, coins + N);

    for (int i = N - 1; i >= 0; i--) {
        if (coins[i].f >= C) {
            ans += coins[i].s;
        } else {
            st = i;
            break;
        }
    }

    while (st != -1) {
        int can[st + 1] {0};
        int cur = 0;
        for (int i = st; i >= 0; i--) {
            if (coins[i].s) {
                int max_fit = (C - cur) / coins[i].f;
                if (max_fit < coins[i].s) {
                    cur += max_fit * coins[i].f;
                    coins[i].s -= max_fit;
                    can[i] = 1;
                } else {
                    cur += coins[i].s * coins[i].f;
                    coins[i].s = 0;
                    if (cur == C) {
                        can[i] = 1;
                    }
                }
            }
        }
        if (cur == C) {
            ans++;
        } else {
            int found = 0;
            for (int i = 0; i <= st; i++) {
                if (can[i]) {
                    coins[i].s--;
                    ans++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                break;
            }
        }
    }
    std::cout << ans << "\n";

    return 0;

}