#include <iostream>
#include <map>

#define MAX 250
#define MOD 1000000007
#define ll long long

ll R, C, K, color[MAX][MAX], dp[MAX][MAX];
std::map<ll, ll> sums[MAX];

int main() {

    std::cin >> R >> C >> K;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            std::cin >> color[r][c];
        }
    }

    sums[0].insert(std::pair<ll, ll> {0, 1});
    sums[0].insert(std::pair<ll, ll> {color[0][0], 1});
    for (int r = 1; r < R; r++) {
        for (int c = 1; c < C; c++) {

            for (int p = 0; p < c; p++) {
                dp[r][c] = ((dp[r][c] + sums[p][0]) % MOD - (sums[p].count(color[r][c]) ? sums[p][color[r][c]] : 0)) % MOD;
                if (dp[r][c] < 0) dp[r][c] += MOD;
            }

        }

        for (int c = 1; c < C; c++) {
            sums[c][0] = (sums[c][0] + dp[r][c]) % MOD;
            sums[c][color[r][c]] = (sums[c][color[r][c]] + dp[r][c]) % MOD;
        }
    }

    std::cout << dp[R - 1][C - 1] << "\n";

    return 0;

}