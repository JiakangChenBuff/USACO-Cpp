#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <set>

#define MAXN 50000
#define INF 2000000000
#define ll long long
#define ii std::pair<ll, ll>
#define f first
#define s second

ll N, A[MAXN], b[4] {INF, 0, INF, 0}, min = (ll) (INF / 2) * (ll) (INF / 2);
std::vector< ii > pts;
std::multiset< ll > X, Y;

int main() {

    std::cin >> N;
    for (int i = 0; i < N; i++) {
        ll x, y; std::cin >> x >> y;
        pts.push_back(std::make_pair(x, y));
        X.insert(x); Y.insert(y);
    }
    std::sort(pts.begin(), pts.end());

    for (int i = 0; i < N; i++) {
        X.erase(X.find(pts[i].f)); Y.erase(Y.find(pts[i].s));
        b[0] = std::min(b[0], pts[i].f); b[1] = std::max(b[1], pts[i].f); b[2] = std::min(b[2], pts[i].s); b[3] = std::max(b[3], pts[i].s);
        if (!X.size() && *X.begin() == b[1] && (!(*Y.begin() >= b[3]) && !(*Y.rbegin() <= b[2]))) {
            A[i] = INF;
        } else {
            A[i] = (b[1] - b[0]) * (b[3] - b[2]) + ((X.size() == 0) ? 0 : (*X.rbegin() - *X.begin()) * (*Y.rbegin() - *Y.begin()));
        }
    }
    for (int i = 0; i < N; i++) {
        min = std::min(min, A[i]);
    }

    X.clear(); Y.clear(); b[0] = INF, b[1] = 0, b[2] = INF, b[3] = 0;
    for (int i = 0; i < N; i++) {
        A[i] = 0;
        std::swap(pts[i].f, pts[i].s);
        X.insert(pts[i].f); Y.insert(pts[i].s);
    }
    std::sort(pts.begin(), pts.end());

    for (int i = 0; i < N; i++) {
        X.erase(X.find(pts[i].f)); Y.erase(Y.find(pts[i].s));
        b[0] = std::min(b[0], pts[i].f); b[1] = std::max(b[1], pts[i].f); b[2] = std::min(b[2], pts[i].s); b[3] = std::max(b[3], pts[i].s);
        if (!X.size() && *X.begin() == b[1] && (!(*Y.begin() >= b[3]) && !(*Y.rbegin() <= b[2]))) {
            A[i] = INF;
        } else {
            A[i] = (b[1] - b[0]) * (b[3] - b[2]) + ((X.size() == 0) ? 0 : (*X.rbegin() - *X.begin()) * (*Y.rbegin() - *Y.begin()));
        }
    }
    for (int i = 0; i < N; i++) {
        min = std::min(min, A[i]);
    }

    std::cout << (A[N - 1] - min) << '\n';
    return 0;

}