#include <iostream>
#include <utility>
#include <string>

#define INF 1000000
#define ll long long
#define ii std::pair<ll, ll>
#define f first
#define s second

ll L, T, vis[50][128], init, pfork, max_zero = 0, ans = INF;
ii dp[50][128];

ll btod(std::string x) {
    ll res = 0;
    for (ll i = 0; i < x.size(); i++) {
        ll sum = (((ll) 1 << i) * (ll) (x[x.size() - 1 - i] - 48));
        res = res + sum;
    }
    return res;
}

ll extract(ll i, ll from) {
    return ((((ll) ((1 << T) - 1) << (L - T - i)) & from) >> (L - T - i));
}

int main() {

    std::cin >> L >> T;
    std::string str; std::cin >> str; init = btod(str);
    std::cin >> str; pfork = btod(str);

    for (ll i = 0; i < 50; i++) {
        for (ll j = 0; j < 128; j++) {
            dp[i][j].s = INF;
        }
    }

    dp[T - 1][extract(0, init)] = std::make_pair(0, 0);
    vis[T - 1][extract(0, init)] = 1;

    for (ll i = T - 1; i < L - 1; i++) {

        for (ll j = 0; j < (1 << T); j++) {

            if (vis[i][j]) {

                ll num_zeroes = ((j & ((ll) 1 << (T - 1))) ? 0 : 1) + dp[i][j].f;
                ll new_j = ((j & (((ll) 1 << (T - 1)) - 1)) << 1) + ((init & ((ll) 1 << (L - i - 2))) >> (L - i - 2));
                if (num_zeroes > dp[i + 1][new_j].f) {
                    dp[i + 1][new_j].f = num_zeroes;
                    dp[i + 1][new_j].s = dp[i][j].s;
                } else if (num_zeroes == dp[i + 1][new_j].f) {
                    dp[i + 1][new_j].s = std::min(dp[i + 1][new_j].s, dp[i][j].s);
                }
                vis[i + 1][new_j] = 1;

                num_zeroes = (((j ^ pfork) & ((ll) 1 << (T - 1))) ? 0 : 1) + dp[i][j].f;
                new_j = (((j ^ pfork) & (((ll) 1 << (T - 1)) - 1)) << 1) + ((init & ((ll) 1 << (L - i - 2))) >> (L - i - 2));
                if (num_zeroes > dp[i + 1][new_j].f) {
                    dp[i + 1][new_j].f = num_zeroes;
                    dp[i + 1][new_j].s = dp[i][j].s + 1;
                } else if (num_zeroes == dp[i + 1][new_j].f) {
                    dp[i + 1][new_j].s = std::min(dp[i + 1][new_j].s, dp[i][j].s + 1);
                }
                vis[i + 1][new_j] = 1;
                
            }

        }

    }

    for (ll j = 0; j < (1 << T); j++) {

        if (vis[L - 1][j]) {

            ll num_zeroes = T - __builtin_popcount(j) + dp[L - 1][j].f;
            if (num_zeroes > max_zero) {
                max_zero = num_zeroes;
                ans = dp[L - 1][j].s;
            } else if (num_zeroes == max_zero) {
                ans = std::min(ans, dp[L - 1][j].s);
            }

            num_zeroes = T - __builtin_popcount(j ^ pfork) + dp[L - 1][j].f;
            if (num_zeroes > max_zero) {
                max_zero = num_zeroes;
                ans = dp[L - 1][j].s + 1;
            } else if (num_zeroes == max_zero) {
                ans = std::min(ans, dp[L - 1][j].s + 1);
            }

        }

    }

    if (T > L) {
        std::cout << (L - __builtin_popcount(init)) << "\n";
    } else {
        std::cout << ans << "\n";
    }

    return 0;

}