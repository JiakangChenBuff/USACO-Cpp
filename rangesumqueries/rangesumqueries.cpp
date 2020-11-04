#include <bits/stdc++.h>

#define MAXN 200005
#define ll long long

ll n, q, tree[MAXN], arr[MAXN];

void update(ll x, ll v) {
    while (x <= MAXN) {
        tree[x] += v;
        x += x & (-x);
    }
}

ll query(int x) {
    ll sum = 0;
    while (x > 0) {
        sum += tree[x];
        x -= x & (-x);
    }
    return sum;
}

int main() {

    std::cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        std::cin >> arr[i];
        update(i, arr[i]);
    }
    for (int i = 0; i < q; i++) {
        ll cmd; std::cin >> cmd;
        if (cmd == 1) {
            ll k, u; std::cin >> k >> u;
            update(k, u - arr[k]);
            arr[k] = u;
        } else {
            ll a, b; std::cin >> a >> b;
            std::cout << query(b) - query(a - 1) << '\n';
        }
    }

    return 0;

}