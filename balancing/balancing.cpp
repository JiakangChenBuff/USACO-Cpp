#include <bits/stdc++.h>

#define MAXN 1005
#define ii std::pair<int, int>
#define f first
#define s second

int N;
ii X[MAXN], Y[MAXN];

int main() {

    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> X[i].f >> X[i].s;
        Y[i].f = X[i].s; Y[i].s = X[i].f;
    }
    std::sort(X, X + N);
    std::sort(Y, Y + N);
    int ans = 1000000;

    for (int i = 0; i < N; i++) {
        while (i + 1 < N && X[i + 1].f == X[i].f) {
            i++;
        }
        int bL = 0; int bR = 0;
        for (int j = 0; j < N; j++) {
            while (j + 1 < N && Y[j + 1].f == Y[j].f) {
                if (Y[j].s < X[i].f + 1) {
                    bL++;
                } else {
                    bR++;
                }
                j++;
            }
            if (Y[j].s < X[i].f + 1) {
                bL++;
            } else {
                bR++;
            }

            ans = std::min(ans, std::max(std::max(bL, bR), std::max(i + 1 - bL, N - i - 1 - bR)));
        }
    }

    std::cout << ans << '\n';

    return 0;

}