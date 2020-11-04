#include <iostream>
#include <cmath>
#include <set>

#define MAX 40105

int N, Nopt, F, M, c[50], dp[MAX], p[MAX], ans, loop;
std::set<int> f;

int recurse(int x) {

    if (dp[x] != -1)
        return dp[x];

    if (p[x]) {
        loop = 1;
        return -1;
    }

    p[x] = 1;

    if (f.count(x) && x != N)
        dp[x] = std::max(dp[x], recurse(x + M));
    else 
        for (int i = 0; i < Nopt; i++)
            if (x - c[i] >= 0)
                dp[x] = std::max(dp[x], c[i] + recurse(x - c[i]));

    p[x] = 0;
    if (dp[x] == -1)
        dp[x] = 0;
    return dp[x];

}

int main() {

    std::cin >> N >> Nopt >> F >> M;
    for (int i = 0; i < Nopt; i++)
        std::cin >> c[i];
    for (int i = 0; i < F; i++) {
        int f_i; std::cin >> f_i;
        f.insert(f_i);    
    }

    for (int i = 1; i <= MAX; i++)
        dp[i] = -1;

    ans = recurse(N);
    if (loop)
        std::cout << "-1\n";
    else
        std::cout << ans << "\n";

    return 0;

}