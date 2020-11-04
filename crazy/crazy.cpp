#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <cmath>
#include <algorithm>

#define MAX 1000
#define E 0.001
#define ll long long
#define ii std::pair<ll, ll>
#define f first
#define s second
#define PI 3.141592653589793

ll N, C, vis[MAX];
ii cows[MAX], pts[MAX];
std::vector< std::vector< ii > > polys;
std::vector< std::vector<ll> > adj(MAX);
std::map< ii , ll > m;
std::string sets[MAX];

int cw(ii a, ii b) {
    if (a.f * b.s - a.s * b.f > 0) {
        return -1;
    } else if (a.f * b.s - a.s * b.f < 0) {
        return 1;
    } else {
        return 0;
    }
}

double angle(ii a, ii b) {
    double ma = std::sqrt(a.f * a.f + a.s * a.s);
    double mb = std::sqrt(b.f * b.f + b.s * b.s);
    double bet = (double) (a.f * b.f + a.s * b.s) / (ma * mb);
    bet = (bet > 1) ? 1 : bet;
    double ret = 180.0 * std::acos(bet) / PI;
    return ret;
}

bool in_poly(ii cow, std::vector< ii > poly) {

    double sum = 0;
    for (int i = 0; i < poly.size(); i++) {
        ii a = std::make_pair(poly[i].f - cow.f, poly[i].s - cow.s);
        ii b = std::make_pair(poly[(i + 1) % poly.size()].f - cow.f, poly[(i + 1) % poly.size()].s - cow.s);
        sum += cw(a, b) * angle(a, b);
    }
    if (std::abs(sum) < E) {
        return false;
    } else {
        return true;
    }

}

int main() {

    std::cin >> N >> C;
    int index = 0;
    for (int i = 0; i < N; i++) {
        ll x1, y1, x2, y2; std::cin >> x1 >> y1 >> x2 >> y2; ii p1 = std::make_pair(x1, y1), p2 = std::make_pair(x2, y2);
        if (!m.count(p1)) {
            m.insert(std::make_pair(p1, index));
            pts[index++] = p1;
        }
        if (!m.count(p2)) {
            m.insert(std::make_pair(p2, index));
            pts[index++] = p2;
        }
        adj[m[p1]].push_back(m[p2]);
        adj[m[p2]].push_back(m[p1]);
    }
    for (int i = 0; i < N; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            polys.push_back(std::vector< ii > {pts[i]});
            std::queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int curr = q.front(); q.pop();
                for (int neigh : adj[curr]) {
                    if (!vis[neigh]) {
                        vis[neigh] = 1;
                        polys.back().push_back(pts[neigh]);
                        q.push(neigh);
                        break;
                    }
                }
            }
        }
    }

    for (int i = 0; i < C; i++) {
        ll x, y; std::cin >> x >> y;
        cows[i] = std::make_pair(x , y);
    }

    for (int i = 0; i < C; i++) {
        sets[i] = "";
    }

    for (int i = 0; i < C; i++) {
        for (int j = 0; j < polys.size(); j++) {
            if (in_poly(cows[i], polys[j])) {
                sets[i] += "1";
            } else {
                sets[i] += "0";
            }
        }
    }

    std::sort(sets, sets + C);
    int max = 0;
    int cur = 0;
    for (int i = 0; i < C; i++) {
        if (i == 0 || sets[i].compare(sets[i - 1])) {
            cur = 1;
        } else {
            cur++;
        }
        max = std::max(max, cur);
    }
    std::cout << max << "\n";

    return 0;

}