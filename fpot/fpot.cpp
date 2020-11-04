#include <bits/stdc++.h>

struct rain {
    int x; int y;

    rain(int a, int b) {
        x = a; y = b;
    }
};

struct cmp1 {
    bool operator()(rain a, rain b) {
        if (a.y == b.y) {
            return a.x > b.x;
        } else {
            return a.y > b.y;
        }
    }
};

bool cmp2(rain a, rain b) {
    return a.x < b.x;
}

#define MAX 2000000

int N, D, ans = MAX;
std::multiset<rain, cmp1> s;
std::vector<rain> raindrops;
std::vector<rain>::iterator l, r;

int main()
{

    std::cin >> N >> D;
    for (int i = 0; i < N; i++) {
        int a, b; std::cin >> a >> b;
        raindrops.push_back(rain(a, b));
    }

    std::sort(raindrops.begin(), raindrops.end(), cmp2);

    l = raindrops.begin();
    r = raindrops.begin();

    s.insert(*l);

    while (r != raindrops.end()) {

        if ((*s.begin()).y - (*s.rbegin()).y >= D) {
            ans = std::min(ans, (*r).x - (*l).x);
            s.erase(*l);
            ++l;
        } else {
            ++r;
            s.insert(*r);
        }

    }
    std::cout << ((ans == MAX) ? -1 : ans) << "\n";

    return 0;
}
