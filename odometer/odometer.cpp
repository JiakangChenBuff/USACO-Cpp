#include <iostream>
#include <vector>

#define ll long long

ll solve(ll x, ll d) {

    std::vector<ll> x_dig;
    while (x > 0) {
        x_dig.insert(x_dig.begin(), x % 10);
        x /= 10;
    }

    ll dp[20][2][50][2] {0};
    dp[0][0][25][1] = 1;

    for (int i = 0; i < x_dig.size(); i++) {
        for (int u = 0; u < 2; u++) {
            for (int diff = 1; diff < 49; diff++) {
                for (int z = 0; z < 2; z++) {
                    for (int dig = 0; dig < 10; dig++) {

                        if (u) {
                            if (z && !dig) {
                                dp[i + 1][u][diff][z] += dp[i][u][diff][z];
                            } else if (dig == d) {
                                dp[i + 1][u][diff + 1][0] += dp[i][u][diff][z];
                            } else {
                                dp[i + 1][u][diff - 1][0] += dp[i][u][diff][z];
                            }
                        } else if (dig <= x_dig[i]) {
                            if (z && !dig) {
                                dp[i + 1][1][diff][z] += dp[i][u][diff][z];
                            } else if (dig == d) {
                                dp[i + 1][(dig == x_dig[i]) ? 0 : 1][diff + 1][0] += dp[i][u][diff][z];
                            } else {
                                dp[i + 1][(dig == x_dig[i]) ? 0 : 1][diff - 1][0] += dp[i][u][diff][z];
                            }
                        }

                    }
                }
            }
        }
    }

    ll total = 0;

    for (int u = 0; u < 2; u++) {
        for (int diff = 25; diff < 49; diff++) {
            total += dp[x_dig.size()][u][diff][0];
        }
    }

    for (int o = 0; o < d; o++) {
        ll dp2[20][2][50][2] {0};
        dp2[0][0][25][1] = 1;
        for (int i = 0; i < x_dig.size(); i++) {
            for (int u = 0; u < 2; u++) {
                for (int diff = 1; diff < 49; diff++) {
                    for (int z = 0; z < 2; z++) {
                        for (int dig = 0; dig < 10; dig++) {
                            
                            if ((z && dig == 0) || dig == d || dig == o) {

                                if (u) {
                                    if (z && !dig) {
                                        dp2[i + 1][u][diff][z] += dp2[i][u][diff][z];
                                    } else if (dig == d) {
                                        dp2[i + 1][u][diff + 1][0] += dp2[i][u][diff][z];
                                    } else {
                                        dp2[i + 1][u][diff - 1][0] += dp2[i][u][diff][z];
                                    }
                                } else if (dig <= x_dig[i]) {
                                    if (z && !dig) {
                                        dp2[i + 1][1][diff][z] += dp2[i][u][diff][z];
                                    } else if (dig == d) {
                                        dp2[i + 1][(dig == x_dig[i]) ? 0 : 1][diff + 1][0] += dp2[i][u][diff][z];
                                    } else {
                                        dp2[i + 1][(dig == x_dig[i]) ? 0 : 1][diff - 1][0] += dp2[i][u][diff][z];
                                    }
                                }

                            }

                        }
                    }
                }
            }
        }
        total = total - dp2[x_dig.size()][0][25][0] - dp2[x_dig.size()][1][25][0];
    }

    return total;

}


int main() {

    ll X, Y; std::cin >> X >> Y;
    
    ll answer = 0;

    for (int i = 0; i < 10; i++) {
        answer += solve(Y, i);
        answer -= solve(X - 1, i);
    }

    std::cout << answer << "\n";

    return 0;

}