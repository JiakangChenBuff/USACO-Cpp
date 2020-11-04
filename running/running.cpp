#include <bits/stdc++.h>

#define MAXN 100005
#define ll long long

ll N, L, C, F, bit[MAXN], P[MAXN];
std::vector< std::vector<ll> > cows(MAXN, std::vector<ll>(3)); 

bool cmp1(std::vector<ll> a, std::vector<ll> b) {
    return a[2] < b[2];
}

bool cmp2(std::vector<ll> a, std::vector<ll> b) {
    if (a[0] == b[0]) {
        return a[2] > b[2];
    } else {
        return a[0] > b[0];
    }
}

void update(int i, int v) {
    while (i <= MAXN) {
        bit[i] += v;
        i += i & (-i);
    }
}

ll query(int i) {
    ll sum = 0;
    while (i > 0) {
        sum += bit[i];
        i -= i & (-i);
    }
    return sum;
}

int main() {

    std::cin >> N >> L >> C;
    for (int i = 0; i < N; i++) {
        std::cin >> cows[i][0];
        if (cows[i][0] > F) {
            F = cows[i][0];
        }
    }
    for (int i = 0; i < N; i++) {
        cows[i][2] = cows[i][0] * L * C % (F * C);
        cows[i][0] = cows[i][0] * L / F;
    }
    std::sort(cows.begin(), cows.begin() + N, cmp1);
    int r = 1; cows[0][1] = 1;
    for (int i = 1; i < N; i++) {
        if (cows[i][2] == cows[i - 1][2]) {
            cows[i][1] = r;
        } else {
            cows[i][1] = ++r;
        }
    }
    std::sort(cows.begin(), cows.begin() + N, cmp2);
    for (int i = 1; i <= N; i++) {
        P[i] = cows[i - 1][0] + P[i - 1];
    }
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans += ((N - i - 1) * cows[i][0] - (P[N] - P[i + 1]));
        ans -= query(cows[i][1] - 1);
        update(cows[i][1], 1);
    }
    std::cout << ans << '\n';

    return 0;

}