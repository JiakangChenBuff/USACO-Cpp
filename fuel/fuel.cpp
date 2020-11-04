#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

#define MAX 50005
#define ll long long

ll N, G, B, D, ns[MAX], ans = 0, possible = 1;
std::stack<ll> s;
std::vector< std::vector<ll> > st(MAX, std::vector<ll> (2));

bool comp(std::vector<ll> a, std::vector<ll> b) {
    return a[0] < b[0];
}

int main() {

    std::cin >> N >> G >> B >> D;
    for (int i = 0; i < N; i++) {
        std::cin >> st[i][0] >> st[i][1];
    }
    std::sort(st.begin(), st.begin() + N, comp);

    ns[N - 1] = -1;
    s.push(N - 1);
    for (int i = N - 2; i >= 0; i--) {
        while (!s.empty() && st[s.top()][1] > st[i][1]) {
            s.pop();
        }
        ns[i] = (s.empty()) ? -1 : s.top();
        s.push(i);
    }

    if (st[0][0] <= B) {
        ll cg = B - st[0][0];
        for (int i = 0; i < N; i++) {
            if (i == N - 1 && D - st[i][0] > G) {
                possible = 0;
                break;
            } else if (i == N - 1) {
                ans += (st[i][1] * ((D - st[i][0] - cg) < 0 ? 0 : (D - st[i][0] - cg)));
            } else if (st[i + 1][0] - st[i][0] > G) {
                possible = 0;
                break;
            } else if (ns[i] == -1 || st[ns[i]][0] - st[i][0] > G) {
                if (D - st[i][0] > G) {
                    ans += (st[i][1] * (G - cg));
                    cg = G - (st[i + 1][0] - st[i][0]);
                } else {
                    ans += (st[i][1] * (D - st[i][0] - cg));
                    i = N - 1;
                }
            } else {
                if (cg >= st[ns[i]][0] - st[i][0]) {
                    cg -= (st[ns[i]][0] - st[i][0]);
                } else {
                    ans += (st[i][1] * (st[ns[i]][0] - st[i][0] - cg));
                    cg = 0;
                }
                i = ns[i] - 1;
            }
        }
        if (possible) {
            std::cout << ans << "\n";
        } else {
            std::cout << "-1\n";
        }
    } else {
        std::cout << "-1\n";
    }
    
    return 0;

}